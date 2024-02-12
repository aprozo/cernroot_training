#!/bin/sh
source /opt/root/bin/thisroot.sh
mkdir ~/.local/share/jupyter/kernels
cp -r $ROOTSYS/etc/notebook/kernels/root ~/.local/share/jupyter/kernels
