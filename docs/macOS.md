# Building & Running on macOS

You will need build tools and CMake. Assuming you have [homebrew](https://docs.brew.sh/Installation) installed:

``` shell
xcode-select --install
brew install cmake
```

TODO: Add instructions for installing python3 and dependencies for tooling

## Installing `gcc-arm-none-eabi`
Once this is done, you'll need to install `gcc-arm-none-eabi`. The easiest way to install this tool is via homebrew with the following source:

``` shell
brew tap ArmMbed/homebrew-formulae
brew install arm-none-eabi-gcc
```

Note:
If you do not want to/ are unable to use homebrew to do this, you should be able to find the install instruction in the `arm-none-eabi-gcc.rb` file in [this repository](https://github.com/ARMmbed/homebrew-formulae).


## Building & Running on 32Blit

If you want to run code on 32Blit, you should now refer to [Building & Running On 32Blit](32blit.md).

## Building & Running Locally

You'll need to build and install SDL2:

``` shell
curl https://www.libsdl.org/release/SDL2-2.0.10.zip -o SDL2-2.0.10.zip
unzip SDL2-2.0.10.zip
cd SDL2-2.0.10
mkdir build
cd build
../configure
make
sudo make install
```

Then, set up the 32Blit Makefile from the root of the repository with the following commands:

```shell
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=../darwin.toolchain
```

Now to make any example, type:

```shell
make example-name
```

For example:

```shell
make raycaster
```

This will produce `examples/raycaster/raycaster` which you should run with:

```shell
./examples/raycaster/raycaster
```

### Build Everything

Alternatively you can build everything by just typing:

```shell
make
```

When the build completes you should be able to run any example.

## Troubleshooting

If you see `cannot create target because another target with the same name already exists` you've probably run `cmake ..` in the wrong directory (the project directory rather than the build directory), you should remove all but your project files and `cmake ..` again from the build directory.