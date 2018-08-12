#include "kernel/version.h"

char * __kernel_name = "skift";

int    __kernel_version_major = 0;
int    __kernel_version_minor = 1;
int    __kernel_version_patch = 0;
char * __kernel_version_codename = "babystep";

/* kernel version format major.minor.patch-codename */
char * __kernel_version_format = "%d.%d.%d-%s";
/* kernel uname format major.minor.patch-codename */
char * __kernel_uname_format = "%s %d.%d.%d-%s";