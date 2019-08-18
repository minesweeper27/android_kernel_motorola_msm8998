# AnyKernel2 Ramdisk Mod Script
# osm0sis @ xda-developers

## AnyKernel setup
# begin properties
properties() {
kernel.string=DELUXE- KERNEL by @Seba_3567
do.devicecheck=1
do.modules=0
do.cleanup=1
do.cleanuponabort=0
device.name1=evert
device.name2=evert_retail
} # end properties

# shell variables
block=/dev/block/bootdevice/by-name/boot;
is_slot_device=0;

## AnyKernel methods (DO NOT CHANGE)
# import patching functions/variables - see for reference
. /tmp/anykernel/tools/ak2-core.sh;


## AnyKernel permissions
# set permissions for included ramdisk files
chmod -R 750 $ramdisk/*;
chown -R root:root $ramdisk/*;

## AnyKernel install
dump_boot;

# begin ramdisk changes

chmod 755 $ramdisk/seba.sh

insert_line init.rc "init.seba.rc" after "import /init.usb.configfs.rc" "import /init.seba.rc";

# end ramdisk changes

write_boot;

## end install

