#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include "libvdpau_foo.h"

void
vl_func(void)
{
  printf("VDPAU: strong\n");
}


void
nouveau_drm_screen_create(void)
{
  printf("VDPAU: screen_create\n");
  vl_func();
}

void
vdp_imp_device_create_x11(void)
{
  printf("VDPAU: entry point\n");
  nouveau_drm_screen_create();
}
