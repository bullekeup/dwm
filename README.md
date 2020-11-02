# My own build of suckless's dynamic window manager

See dwm [website](https://dwm.suckless.org/).
Vanilla dwm from official git repo in branch main.
My own build with various patches and my own modifications in branch dev.

My config and scripts to go with dwm can be found [here](https://github.com/bullekeup/dwm-config).
Used with [polybar-dwm-module]() and my [polybar-dwm-config](https://github.com/bullekeup/polybar-dwm-config).
You can also check my Xorg related scripts and tools (dwm / polybar / config auto-installer script) [here](https://github.com/bullekeup/Xorg-wm-tools).

## patches and features

See the patches/getpatches.sh script in dev branch.

Added a fixedontop property to allow some clients to always appear on top (but may not be floating, ex : conky clients). Added a user_bh_percent var in config.def.h to manually set the bar height to a percentage of screen height. Added a user_lrpad var in config.def.h to manually set the lrpad value.

I do not have generated patches from my modifications, if you need insights see my commit log. If really needed, ask for a patch, I may do one if it really can be usefull to others.

## dependencies

yajl: Needed for dwm ipc patch

Check patches and dwm requierements for a list of dependencies.

