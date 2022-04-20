

EnsureSConsVersion(2, 0)

import sys

sys.path.insert(1, './support/scons')

from build import *

#
# Target build
#
build_env = target
Export('build_env')

# Build programs, libraries and servers.
VariantDir(target['BUILDROOT'] + '/lib', '#lib', duplicate = 0)
VariantDir(target['BUILDROOT'] + '/bin', '#bin', duplicate = 0)
VariantDir(target['BUILDROOT'] + '/server', '#server', duplicate = 0)
VariantDir(target['BUILDROOT'] + '/test', '#test', duplicate = 0)
VariantDir(target['BUILDROOT'] + '/kernel', '#kernel', duplicate = 0)

# Install files to the target RootFS
target.Lz4Compress4K('#${BUILDROOT}/include/Config.h.lz4', '#${BUILDROOT}/include/Config.h')
target.TargetInstall('VERSION', target['etc'])
target.TargetInstall('build.conf', target['etc'])
target.TargetInstall('build.host.conf', target['etc'])
target.TargetInstall(target['BUILDROOT'] + '/include/Config.h', target['etc'])
target.TargetInstall(target['BUILDROOT'] + '/include/Config.h.lz4', target['etc'])
target.TargetInstall('config/' + target['ARCH'] + '/' + target['SYSTEM'] + '/init.sh', target['etc'])

SConscript(target['BUILDROOT'] + '/lib/SConscript')
SConscript(target['BUILDROOT'] + '/bin/SConscript')
SConscript(target['BUILDROOT'] + '/server/SConscript')
SConscript(target['BUILDROOT'] + '/test/SConscript')
SConscript(target['BUILDROOT'] + '/kernel/' + target['ARCH'] + '/' + target['SYSTEM'] + '/SConscript')

#
# Host build
#
build_env = host
Export('build_env')

# Copy files from the target
host.Install('#${BUILDROOT}/etc', target['BUILDROOT'] + '/include/Config.h')
host.Install('#${BUILDROOT}/etc', target['BUILDROOT'] + '/include/Config.h.lz4')

# Build programs and libraries.
VariantDir(host['BUILDROOT'] + '/lib', '#lib', duplicate = 0)
VariantDir(host['BUILDROOT'] + '/bin', '#bin', duplicate = 0)
VariantDir(host['BUILDROOT'] + '/server', '#server', duplicate = 0)
VariantDir(host['BUILDROOT'] + '/test', '#test', duplicate = 0)

if host['MINIMAL_BUILD'] == True:
    SConscript(host['BUILDROOT'] + '/lib/libstd/SConscript')
    SConscript(host['BUILDROOT'] + '/lib/libarch/SConscript')
    SConscript(host['BUILDROOT'] + '/lib/libexec/SConscript')
    SConscript(host['BUILDROOT'] + '/lib/libapp/SConscript')
    SConscript(host['BUILDROOT'] + '/lib/libfs/SConscript')
    SConscript(host['BUILDROOT'] + '/bin/img/SConscript')
    SConscript(host['BUILDROOT'] + '/server/filesystem/linn/SConscript')
else:
    SConscript(host['BUILDROOT'] + '/lib/SConscript')
    SConscript(host['BUILDROOT'] + '/bin/SConscript')
    SConscript(host['BUILDROOT'] + '/server/SConscript')
    SConscript(host['BUILDROOT'] + '/test/SConscript')

#
# RootFS
#
Import('rootfs_files')
target.LinnImage('#${BUILDROOT}/rootfs.linn', rootfs_files)
target.Depends('#${BUILDROOT}/rootfs.linn', '#build/host/server/filesystem/linn/create')
target.Depends('#${BUILDROOT}/rootfs.linn', '#build/host/bin/img/img')

#
# Boot Image
#
target.BootImage('#${BUILDROOT}/boot.img', '#config/' + target['ARCH'] + '/' + target['SYSTEM'] + '/boot.imgdesc')
target.Lz4Compress('#${BUILDROOT}/boot.img.lz4', '#${BUILDROOT}/boot.img')
host.Install('#${BUILDROOT}', target['BUILDROOT'] + '/boot.img')
host.Install('#${BUILDROOT}', target['BUILDROOT'] + '/boot.img.lz4')

#
# Source Release
#
target.Targets(release = 'git archive --format tar --prefix "Nicoos-${VERSION}/" HEAD | gzip > "Nicoos-${VERSION}.tar.gz"; \
                          git log --decorate=short > ChangeLog-${VERSION}; \
                          md5sum "Nicoos-${VERSION}.tar.gz" > "Nicoos-${VERSION}.tar.gz.md5"; \
                          sha1sum "Nicoos-${VERSION}.tar.gz" > "Nicoos-${VERSION}.tar.gz.sha1"')
