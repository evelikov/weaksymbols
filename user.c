#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>

static void (*__driDriverGetExtensions_foo)(void);
static void (*vdp_imp_device_create_x11)(void);

static void
initial_setup(void)
{
  void *handleA, *handleB;

  // XXX: Experiment with local ?
#ifdef USE_FOO_DRI_FIRST
  handleA = dlopen("foo_dri.so", RTLD_NOW | RTLD_GLOBAL);
#endif // USE_FOO_DRI_FIRST

  handleB = dlopen("libvdpau_foo.so", RTLD_NOW | RTLD_GLOBAL);

#ifndef USE_FOO_DRI_FIRST
  handleA = dlopen("foo_dri.so", RTLD_NOW | RTLD_GLOBAL);
#endif // USE_FOO_DRI_FIRST

  if (!handleA || !handleB) {
    printf("failed to dlopen\n");
    exit(-1);
  }

#ifdef USE_FOO_DRI_FIRST
  __driDriverGetExtensions_foo = dlsym(handleA, "__driDriverGetExtensions_foo");
#endif // USE_FOO_DRI_FIRST

  vdp_imp_device_create_x11 = dlsym(handleB, "vdp_imp_device_create_x11");

#ifndef USE_FOO_DRI_FIRST
  __driDriverGetExtensions_foo = dlsym(handleA, "__driDriverGetExtensions_foo");
#endif // USE_FOO_DRI_FIRST

  if (!__driDriverGetExtensions_foo || !vdp_imp_device_create_x11) {
    printf("failed to dlsym\n");
    exit(-1);
  }

}

int
main(void)
{
  initial_setup();

#ifdef USE_FOO_DRI_FIRST
  __driDriverGetExtensions_foo();
#endif // USE_FOO_DRI_FIRST

  vdp_imp_device_create_x11();

#ifndef USE_FOO_DRI_FIRST
  __driDriverGetExtensions_foo();
#endif // USE_FOO_DRI_FIRST

  return 0;
}
