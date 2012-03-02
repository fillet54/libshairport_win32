#/bin/sh

export CFLAGS="-DXBMC -DWIN32 -NDEBUG"
export LDFLAGS="-lws2_32 -no-undefined"
./configure && make