# mcl

minecraft launcher for linux

## what does it do

- download all versions (works with tested modded versions)
- run versions from downloaded json/jar pairs
- download assets and libraries
- set up natives
- select the correct libraries for the version (may only work on linux)
- get an authentication token (microsoft auth only, i no longer have a mojang account)
- instance support
- multiple account support
- launch the game

## what does it *not* do

- import minecraft launcher profiles - you will have to manually create profiles for optifine, forge, etc after installation
- support external natives (openbsd, freebsd, etc) with the exception of aarch64 linux

## what will it *never* do
- support windows. it is not a very command line centric operating system

## why not use the regular launcher

- closed source
- really buggy for some reason
- much slower in practice
- it is more fun to write one

## why not a third party launcher

- too complex (heavy guis and such)
- they all have Discourse
