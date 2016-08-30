--- ALAC_original/convert-utility/main.cpp	2013-02-04 18:32:05.000000000 -0500
+++ ALAC/convert-utility/main.cpp	2013-01-30 13:53:34.000000000 -0500
@@ -235,7 +235,15 @@
                         theInputFormat->mChannelsPerFrame = theReadBuffer[6];
                         theSampleRate = ((int32_t)(theReadBuffer[11]) << 24) + ((int32_t)(theReadBuffer[10]) << 16) + ((int32_t)(theReadBuffer[9]) << 8) + theReadBuffer[8];
                         theInputFormat->mSampleRate = theSampleRate;
-                        theInputFormat->mBitsPerChannel = theReadBuffer[18];
+                        // Check the bit depth of the WAV file; if it's 16 or 24, proceed.
+                        if (theReadBuffer[18] == 16 || theReadBuffer[18] == 24) {
+                            theInputFormat->mBitsPerChannel = theReadBuffer[18];
+                        }
+                        else {
+                            // If not, kill it dead.
+                            *theFileType = 0;
+                            return -1;
+                        }
                         theInputFormat->mFormatFlags = kALACFormatFlagIsSignedInteger | kALACFormatFlagIsPacked; // always little endian
                         theInputFormat->mBytesPerPacket = theInputFormat->mBytesPerFrame = (theInputFormat->mBitsPerChannel >> 3) * theInputFormat->mChannelsPerFrame;
                         theInputFormat->mFramesPerPacket = 1;
