TEMPLATE = subdirs

SUBDIRS += \
    logic \
    ui

CONFIG += \
    ordered \ # Build projects from the first to the last.
    qtc_runnable
