#
#	Dark Builder - Designed and Created by James Walmsley
#
#	Dark Builder attempts to provide a clean framework for creating organised
#	and "pretty" builds with minimal effort.
#
#	Dark Builder is based upon the vebuild as found in the FullFAT project
#	in the .vebuild directory.
#
#	@see		github.com/FullFAT/FullFAT/
#	@author		James Walmsley	<jwalmsley@riegl.com>
#
#	@version	1.4.0 (
#

DBUILD_VERSION_MAJOR 	:= 1
DBUILD_VERSION_MINOR 	:= 4
DBUILD_VERSION_REVISION	:= 0

DBUILD_VERSION_NAME := Aldrin
DBUILD_VERSION_DATE := September 2013

#
#	Let's ensure we have a pure make environment.
#	(Delete all rules and variables).
#
MAKEFLAGS += -rR --no-print-directory

all: dbuild_entry _all
#
#	Optional Include directive, blue build attempts to build using lists of objects,
#	targets and subdirs as found in objects.mk and subdirs.mk
#
-include $(BASE).config.mk
-include objects.mk
-include targets.mk
-include subdirs.mk

#
#	Simple backwards compatible for configurable object builds!
#
OBJECTS += $(OBJECTS-y)

#
#	A config file can be overidden or extended in any sub-directory
#
-include dbuild.config.mk
-include $(BUILD_ROOT)dbuild.config.mk

#
#	Defaults for compile/build toolchain
#
override TOOLCHAIN 	?=
override AR			= $(TOOLCHAIN)ar
override AS			= $(TOOLCHAIN)as
override CC		 	= $(TOOLCHAIN)gcc
override CXX		= $(TOOLCHAIN)g++
override LD			= $(TOOLCHAIN)ld
override OBJCOPY	= $(TOOLCHAIN)objcopy
override OBJDUMP	= $(TOOLCHAIN)objdump
override SIZE		= $(TOOLCHAIN)size

CFLAGS		+= -c

#
#	Incase the .config.mk file does not exist, create a blank one.
#	We should eventually integrate this with KConfig or something nice.
#
.config.mk:
	@touch .config.mk

$(TARGETS) $(TARGET_DEPS): .config.mk

include $(BASE).dbuild/verbosity.mk
include $(BASE).dbuild/pretty.mk
include $(BASE).dbuild/subdirs.mk
include $(BASE).dbuild/clean.mk
include $(BASE).dbuild/module-link.mk
include $(BASE).dbuild/c-objects.mk
include $(BASE).dbuild/cpp-objects.mk
include $(BASE).dbuild/asm-objects.mk
include $(BASE).dbuild/info.mk
include $(BASE).dbuild/configure.mk
include $(BASE).dbuild/install.mk
include $(BASE).dbuild/distclean.mk


#
#	Provide a default target named all,
#	This is dependent on $(TARGETS) and $(SUBDIRS)
#
#	All is finally dependent on silent, to keep make silent when it has
#	nothing to do.
#
dbuild_entry: dbuild_splash | _all
$(TARGETS) $(SUBDIR_LIST) $(MODULE_TARGET) $(OBJECTS) clean: | dbuild_splash
_all: $(TARGETS) $(SUBDIR_LIST) $(MODULE_TARGET) | silent

#
#	DBuild Splash
#
.PHONY: dbuild_splash
dbuild_splash:
ifeq ($(DBUILD_SPLASHED), 1)
else
	@echo " Dark Builder"
	@echo " Version ($(DBUILD_VERSION_MAJOR).$(DBUILD_VERSION_MINOR).$(DBUILD_VERSION_REVISION) - $(DBUILD_VERSION_NAME))"
endif

#
#	Finally provide an implementation of the silent target.
#
silent:
	@:
