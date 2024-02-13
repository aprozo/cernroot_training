#!/bin/bash
cp -r $ROOTSYS/etc/notebook/kernels/root ~/.local/share/jupyter/kernels
jupyter notebook --allow-root
