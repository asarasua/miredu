
/* MIR.EDU vamp library
 *
 * Feature name: Zero Crossing Rate
 * Description: Compute the zero crossing rate of the signal in each frame.
 * Unit: crossings/second
 * Formula: See reference. We consider >=0 as positive, <0 as negative.
 * Reference: http://en.wikipedia.org/wiki/Zero-crossing_rate
 */


// Remember to use a different guard symbol in each header!
#ifndef _ZEROCROSSINGRATE_H_
#define _ZEROCROSSINGRATE_H_

#include <vamp-sdk/Plugin.h>

using std::string;


class ZeroCrossingRate : public Vamp::Plugin
{
public:
    ZeroCrossingRate(float inputSampleRate);
    virtual ~ZeroCrossingRate();

    string getIdentifier() const;
    string getName() const;
    string getDescription() const;
    string getMaker() const;
    int getPluginVersion() const;
    string getCopyright() const;

    InputDomain getInputDomain() const;
    size_t getPreferredBlockSize() const;
    size_t getPreferredStepSize() const;
    size_t getMinChannelCount() const;
    size_t getMaxChannelCount() const;

    ParameterList getParameterDescriptors() const;
    float getParameter(string identifier) const;
    void setParameter(string identifier, float value);

    ProgramList getPrograms() const;
    string getCurrentProgram() const;
    void selectProgram(string name);

    OutputList getOutputDescriptors() const;

    bool initialise(size_t channels, size_t stepSize, size_t blockSize);
    void reset();

    FeatureSet process(const float *const *inputBuffers,
                       Vamp::RealTime timestamp);

    FeatureSet getRemainingFeatures();

protected:
    // plugin-specific data and methods go here
	size_t m_blockSize;
	size_t m_stepSize;
};



#endif // _ZEROCROSSINGRATE_H_