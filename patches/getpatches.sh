#!/bin/sh
# Retrieves needed patches from dwm.suckless.org/patches/ or any other source (github, ... ) using curl

[ -n "$(command -v curl)" ] || { echo "Error : needs curl to download patches"; exit 1; }

# actualfullscreen -> Toggle a window fullscreen
curl -LO https://dwm.suckless.org/patches/actualfullscreen/dwm-actualfullscreen-20191112-cb3f58a.diff

# alwaysfullscreen -> Do not allow focus to drift from active fullscreen window
curl -LO https://dwm.suckless.org/patches/alwaysfullscreen/dwm-alwaysfullscreen-6.1.diff

# anybar -> allows dwm to manage external bars as its own
curl -LO https://github.com/mihirlad55/dwm-anybar/releases/download/v1.1.1/dwm-anybar-polybar-tray-fix-20200905-bb2e722.diff

# autostart -> dwm run ~/.dwm/autostart_blocking.sh and ~/.dwm/autostart.sh & (XDG Base Directory conformant version)
curl -LO https://dwm.suckless.org/patches/autostart/dwm-autostart-20200610-cb3f58a.diff

# bottomstack -> bstack and bstackhoriz are two stack layouts for dwm
curl -LO https://dwm.suckless.org/patches/bottomstack/dwm-bottomstack-6.1.diff

# center -> Add an iscentered rule to automatically center clients on the current monitor
curl -LO https://dwm.suckless.org/patches/center/dwm-center-6.2.diff

# decorationhints -> Make dwm respect _MOTIF_WM_HINTS property
curl -LO https://dwm.suckless.org/patches/decoration_hints/dwm-decorhints-6.2.diff

# ewmhtags -> adds EWMH for workspace info. Usefull for bars, e.g polybar
curl -LO https://dwm.suckless.org/patches/ewmhtags/dwm-ewmhtags-6.2.diff

# fibonacci layout -> adds spiral and dwindle layouts
curl -LO https://dwm.suckless.org/patches/fibonacci/dwm-fibonacci-20200418-c82db69.diff

# fullgaps -> Add gaps between client windows. with Gap struct to use with pertag patch
curl -LO https://dwm.suckless.org/patches/fullgaps/dwm-fullgaps-toggle-20200830.diff

# gapless grid layout -> grid layout with no gap (empty cell)
curl -LO https://dwm.suckless.org/patches/gaplessgrid/dwm-gaplessgrid-20160731-56a31dc.diff

# ipc patch -> to control / get events from dwm on an UNIX socket. Needs yajl library
curl -LO https://dwm.suckless.org/patches/ipc/dwm-ipc-20200824-f04cac6.diff

# namedscratchpads -> Allows for the creation of multiple scratchpad windows, each assigned to different keybinds
curl -LO https://dwm.suckless.org/patches/namedscratchpads/dwm-namedscratchpads-6.2.diff

# onlyquitonempty -> dwm exits only if no windows are open
curl -LO https://dwm.suckless.org/patches/onlyquitonempty/dwm-onlyquitonempty-20180428-6.2.diff

# pertag -> This patch keeps layout, mwfact, barpos and nmaster per tag
curl -LO https://dwm.suckless.org/patches/pertag/dwm-pertag-20200914-61bb8b2.diff

# sticky -> make a window sticky (visible on all tags)
curl -LO https://dwm.suckless.org/patches/sticky/dwm-sticky-6.1.diff

# swallow -> add window swallowing to dwm
curl -LO https://dwm.suckless.org/patches/swallow/dwm-swallow-20200807-b2de9b0.diff

# barpadding -> add a variable to manually add padding for a top bar
curl -LO https://dwm.suckless.org/patches/barpadding/dwm-barpadding-20200720-bb2e722.diff

# bar height -> add a custom variable to manually define the top bar height
curl -LO https://dwm.suckless.org/patches/bar_height/dwm-bar-height-6.2.diff
