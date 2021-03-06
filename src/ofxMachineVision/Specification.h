#pragma once

#include <set>
#include <string>

#include "Constants.h"
using namespace std;

namespace ofxMachineVision {
	class Specification {
    public:    
        typedef std::set<Feature> FeatureSet;
        typedef std::set<PixelMode> PixelModeSet;
        typedef std::set<TriggerMode> TriggerModeSet;
        typedef std::set<TriggerSignalType> TriggerSignalTypeSet;
		typedef std::set<GPOMode> GPOModeSet;

        Specification();
		Specification(int deviceID) { this->deviceID = deviceID;}
        Specification(const Specification &);
        Specification(int sensorWidth, int sensorHeight, string manufacturer, string modelName, string serialNumber = "");
            
        bool getValid() const { return this->valid; }
		int getDeviceID() const { return this->deviceID; }
			
        const FeatureSet & getFeatures() const { return this->features; }
        const PixelModeSet & getPixelModes() const { return this->pixelModes; }
        const TriggerModeSet & getTriggerModes() const { return this->triggerModes; }
        const TriggerSignalTypeSet & getTriggerSignalTypes() const { return this->triggerSignalTypes; }
		const GPOModeSet & getGPOModes() const { return this->gpoModes; }

        bool supports(const Feature &) const;
        bool supports(const PixelMode &) const;
        bool supports(const TriggerMode &) const;
        bool supports(const TriggerSignalType &) const;
		bool supports(const GPOMode &) const;

        int getSensorWidth() const { return this->sensorWidth; }
        int getSensorHeight() const { return this->sensorHeight; }

        const string & getManufacturer() const { return this->manufacturer; }
        const string & getModelName() const { return this->modelName; }
		const string & getSerialNumber() const { return this->serialNumber; }

        string toString() const;
		friend ostream& operator<<(ostream&, const Specification&);

		void setDeviceID(int deviceID) { this->deviceID = deviceID; }
        void addFeature(const Feature &);
        void addPixelMode(const PixelMode &);
        void addTriggerMode(const TriggerMode &);
        void addTriggerSignalType(const TriggerSignalType &);
		void addGPOMode(const GPOMode &);

    protected:
        bool valid;
        FeatureSet features;
        PixelModeSet pixelModes;
        TriggerModeSet triggerModes;
        TriggerSignalTypeSet triggerSignalTypes;
		GPOModeSet gpoModes;

        int sensorWidth;
        int sensorHeight;
            
        string manufacturer;
        string modelName;
		string serialNumber;
			
		int deviceID;
    };

	//---------
	inline ostream& operator<<(ostream& os, const Specification& specification) {
		os << specification.toString();
		return os;
	}
}
