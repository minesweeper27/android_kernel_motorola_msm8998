dts-dirs += altera
dts-dirs += amd
dts-dirs += apm
dts-dirs += arm
dts-dirs += broadcom
dts-dirs += cavium
dts-dirs += exynos
dts-dirs += freescale
dts-dirs += hisilicon
dts-dirs += marvell
dts-dirs += mediatek
dts-dirs += qcom
dts-dirs += rockchip
dts-dirs += sprd
dts-dirs += xilinx

subdir-y	:= $(dts-dirs)

dtstree		:= $(srctree)/$(src)

dtb-$(CONFIG_OF_ALL_DTBS) := $(patsubst $(dtstree)/%.dts,%.dtb, $(foreach d,$(dts-dirs), $(wildcard $(dtstree)/$(d)/*.dts)))

always		:= $(dtb-y)
<<<<<<< HEAD
targets += dtbs
=======
>>>>>>> b67a656dc4bbb15e253c12fe55ba80d423c43f22
