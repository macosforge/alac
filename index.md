---
title: Apple Lossless Audio Codec
---

{:.lead}
The Apple Lossless Audio Codec (ALAC) is an audio codec developed by Apple and supported on iPhone, iPad, most iPods, Mac and iTunes. ALAC is a data compression method which reduces the size of audio files with no loss of information. A decoded ALAC stream is bit-for-bit identical to the original uncompressed audio file.

The Apple Lossless Audio Codec project contains the sources for the ALAC encoder and decoder. Also included is an example command line utility, called alacconvert, to read and write audio data to/from Core Audio Format (CAF) and WAVE files. A description of a 'magic cookie' for use with files based on the ISO base media file format (e.g. MP4 and M4A) is included as well.

The Apple Lossless Audio Codec sources are available under the [Apache license](https://www.apache.org/licenses/LICENSE-2.0).

## Source Code

The ALAC source code can be accessed via git. To clone the repository, use the following command line to create a directory named ALAC in the current local directory:

    git clone https://github.com/macosforge/alac.git ALAC

## libalac.a

Within the codec directory there is a makefile to create a static library of the ALAC encoder/decoder. From within the codec directory, invoke the makefile by the following command to create libalac.a and the associated .o files:

    make

## Building alacconvert

To demonstrate how to encode/decode ALAC to/from audio files, build the alacconvert command line utility. The utility accepts CAF/WAVE files containing pcm data for encoding ALAC into a CAF file. It accepts CAF files containing ALAC for decoding to pcm in CAF/WAVE files. Within the convert-utility directory there are three projects; ALACconvert.xcodeproj (macOS), ALACconvert.vcproj (Windows), makefile (generic UNIX makefile).

The macOS and Windows projects compile the decoder/encoder directly into the alacconvert tool. The UNIX makefile builds libalac.a first and links against the static library for compiling the tool.

As mentioned in the ReadMe, the Windows project requires &lt;stdint.h&gt;, and this is only installed by default with Visual Studio 2010. The code is in the public domain, however, and it should be fairly easy to locate a copy.

## Using alacconvert

To encode:

    alacconvert sourcefile.caf outputfile.caf
    alacconvert sourcefile.wav outputfile.caf

To decode:

    alacconvert sourcefile.caf outputfile.caf
    alacconvert sourcefile.caf outputfile.wav
