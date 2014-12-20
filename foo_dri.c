#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include "foo_dri.h"

#if 0
__attribute__((weak)) void
vl_func(void)
{
  printf("DRI: weak\n");
}
#endif

void
nouveau_drm_screen_create(void)
{
  printf("DRI: screen_create\n");
  vl_func();
}

void
__driDriverGetExtensions_foo(void)
{
  printf("DRI: entry point\n");
  nouveau_drm_screen_create();
}
