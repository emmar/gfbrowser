################################################################################
#
# gfbrowser
#
################################################################################


GFBROWSER_VERSION = master
GFBROWSER_SITE = https://github.com/emmar/gfbrowser.git
GFBROWSER_SITE_METHOD = git
GFBROWSER_LICENSE = GPLv3

ifeq ($(BR2_PACKAGE_QT5WEBKIT),y)
        GFBROWSER_DEPENDENCIES = qt5webkit
endif

define GFBROWSER_CONFIGURE_CMDS
        (cd $(@D); \
                $(TARGET_MAKE_ENV) \
                $(HOST_DIR)/usr/bin/qmake \
                        ./gfbrowser.pro \
        )
endef


define GFBROWSER_BUILD_CMDS
        $(TARGET_MAKE_ENV) $(MAKE) -C $(@D)
endef

define GFBROWSER_INSTALL_TARGET_CMDS
        $(INSTALL) -D -m 0755 $(@D)/gfbrowser $(TARGET_DIR)/usr/bin
endef

define GFBROWSER_UNINSTALL_TARGET_CMDS
        rm -f $(TARGET_DIR)/usr/bin/gfbrowser
endef

$(eval $(generic-package))
