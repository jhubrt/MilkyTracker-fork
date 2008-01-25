/*
 *  SampleEditorControlLastValues.h
 *  milkytracker_universal
 *
 *  Created by Peter Barth on 18.01.08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SAMPLEEDITORCONTROLASTVALUES_H__
#define __SAMPLEEDITORCONTROLASTVALUES_H__

#include "BasicTypes.h"
#include "Dictionary.h"

// Last values
struct SampleEditorControlLastValues
{
	pp_int32 newSampleSize;
	float boostSampleVolume;
	float fadeSampleVolumeStart;
	float fadeSampleVolumeEnd;
	float DCOffset;
	pp_int32 silenceSize;
	float waveFormVolume;
	float waveFormNumPeriods;
	
	bool hasEQ3BandValues;
	float EQ3BandValues[3];
	
	bool hasEQ10BandValues;
	float EQ10BandValues[10];
	
	pp_int32 lastResampleInterpolationType;
	
	static float invalidFloatValue() 
	{
		return -12345678.0f;
	}
	
	static int invalidIntValue() 
	{
		return -12345678;
	}
	
	void reset()
	{
		newSampleSize = invalidIntValue();
		boostSampleVolume = invalidFloatValue();
		fadeSampleVolumeStart = invalidFloatValue();
		fadeSampleVolumeEnd = invalidFloatValue();
		DCOffset = invalidFloatValue();
		silenceSize = invalidIntValue();
		waveFormVolume = invalidFloatValue();
		waveFormNumPeriods = invalidFloatValue();
		hasEQ3BandValues = hasEQ10BandValues = false;
		lastResampleInterpolationType = invalidIntValue();
	}
		
	PPDictionary convertToDictionary()
	{
		PPDictionary result;
		
		result.store("newSampleSize", newSampleSize);

		result.store("boostSampleVolume", PPDictionary::convertFloatToIntNonLossy(boostSampleVolume));

		result.store("fadeSampleVolumeStart", PPDictionary::convertFloatToIntNonLossy(fadeSampleVolumeStart));
		result.store("fadeSampleVolumeEnd", PPDictionary::convertFloatToIntNonLossy(fadeSampleVolumeEnd));

		result.store("DCOffset", PPDictionary::convertFloatToIntNonLossy(DCOffset));

		result.store("silenceSize", silenceSize);

		result.store("waveFormVolume", PPDictionary::convertFloatToIntNonLossy(waveFormVolume));
		result.store("waveFormNumPeriods", PPDictionary::convertFloatToIntNonLossy(waveFormNumPeriods));

		result.store("lastResampleInterpolationType", lastResampleInterpolationType);
		return result;
	}
	
	void restoreFromDictionary(PPDictionary& dictionary)
	{
		PPDictionaryKey* key = dictionary.getFirstKey();
		while (key)
		{
			if (key->getKey().compareToNoCase("newSampleSize") == 0)
			{
				newSampleSize = key->getIntValue();
			}
			else if (key->getKey().compareToNoCase("boostSampleVolume") == 0)
			{
				boostSampleVolume = PPDictionary::convertIntToFloatNonLossy(key->getIntValue());
			}
			else if (key->getKey().compareToNoCase("fadeSampleVolumeStart") == 0)
			{
				fadeSampleVolumeStart = PPDictionary::convertIntToFloatNonLossy(key->getIntValue());
			}
			else if (key->getKey().compareToNoCase("fadeSampleVolumeEnd") == 0)
			{
				fadeSampleVolumeEnd = PPDictionary::convertIntToFloatNonLossy(key->getIntValue());
			}
			else if (key->getKey().compareToNoCase("DCOffset") == 0)
			{
				DCOffset = PPDictionary::convertIntToFloatNonLossy(key->getIntValue());
			}
			else if (key->getKey().compareToNoCase("silenceSize") == 0)
			{
				silenceSize = key->getIntValue();
			}
			else if (key->getKey().compareToNoCase("waveFormVolume") == 0)
			{
				waveFormVolume = PPDictionary::convertIntToFloatNonLossy(key->getIntValue());
			}
			else if (key->getKey().compareToNoCase("waveFormNumPeriods") == 0)
			{
				waveFormNumPeriods = PPDictionary::convertIntToFloatNonLossy(key->getIntValue());
			}
			else if (key->getKey().compareToNoCase("lastResampleInterpolationType") == 0)
			{
				lastResampleInterpolationType = key->getIntValue();
			}
		
			key = dictionary.getNextKey();
		}
	}
};

#endif