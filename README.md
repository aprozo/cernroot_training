# cernroot_training

[![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/aprozo/binder_cern_root/main?urlpath=git-pull%3Frepo%3Dhttps%253A%252F%252Fgithub.com%252Faprozo%252Fcernroot_training%26urlpath%3Dtree%252Fcernroot_training%252F%26branch%3Dmain)
[![Open in GitHub Codespaces](https://github.com/codespaces/badge.svg)](https://codespaces.new/aprozo/cernroot_training?quickstart=1)


Unfortunately, in order to run it with [ROOT C++ kernel](https://github.com/root-project/root/tree/master/bindings/jupyroot), one has to run it in terminal 
``` bash
cp -r $ROOTSYS/etc/notebook/kernels/root ~/.local/share/jupyter/kernels
jupyter notebook --allow-root
```

Then, wait untill the page is reloaded and choose Jupyter Kernel -> ROOT
