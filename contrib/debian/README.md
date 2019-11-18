
Debian
====================
This directory contains files used to package rocketfundcoind/rocketfundcoin-qt
for Debian-based Linux systems. If you compile rocketfundcoind/rocketfundcoin-qt yourself, there are some useful files here.

## rocketfundcoin: URI support ##


rocketfundcoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install rocketfundcoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your rocketfundcoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/rocketfundcoin128.png` to `/usr/share/pixmaps`

rocketfundcoin-qt.protocol (KDE)

