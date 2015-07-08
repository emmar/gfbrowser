# gfbrowser

Basic web browser, can run with other backends but the goal is to run using a EGL backend.  Build using buildroot and the gfbrowser package.  When compiling with QT5 enable qtwebkit, eglfs, opengl support in buildroot-052015.  EGL backend needs to be  available either by mesa3D, rpi-userland, etc.
(Gluten-Free)

Notes:
```
: 'To setup on a non-target ubuntu machine run the following in an ubuntu bash shell:';
    : 'Install developer tools.';
    sudo apt-add-repository -y ppa:ubuntu-sdk-team/ppa; sudo apt-get update;
    sudo apt-get install -y qtdeclarative5-dev libqt5webkit5-dev qt5-default;
    sudo apt-get install -y build-essential mesa-common-dev libglu1-mesa-dev libsqlite3-dev;
    : 'Clone a copy of this repository.';
    git clone https://github.com/emmar/gfbrowser; cd gfbrowser;
    : 'Optionally turn on the DEV_INTERFACE_REQUIRES_MULTI_WINDOW opt flag.'
    sed 's/^#\(DEFINES\)/\1/' gfbrowser.pro; : 'uncomment all DEFINES tags...'
    : 'Compile and run the browser.';
    qmake; make; ./gfbrowser http://www.google.com;
```
