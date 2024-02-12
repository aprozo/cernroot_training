#!/bin/sh
mkdir ~/.local/share/jupyter/kernels
cp -r $ROOTSYS/etc/notebook/kernels/root ~/.local/share/jupyter/kernels
jupyter notebook --allow-root
