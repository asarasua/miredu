
/* MIR.EDU vamp library
 *
 * Feature name: Attack Start/End Times
 * Description: Compute the start and end times of the attack of the signal.
 * Unit: time (seconds)
 * Formula: See reference.
 * NOTE: the values are returned as timestamps.
 * NOTE 2: the accuracy of the estimation depends on the step (hop) size of the analysis, the
 * smaller the better.
 * Reference: http://asadl.org/jasa/resource/1/jasman/v130/i5/p2902_s1/cart.do
 * PDF: http://mt.music.mcgill.ca/mpcl/publications/peeters-giordano-susini-misdariis-mcadams-2011
 */


// Remember to use a different guard symbol in each header!
#ifndef _ATTACKSTARTENDTIMES_H_
#define _ATTACKSTARTENDTIMES_H_

#include <vector>
#include <algorithm>
#include <cmath>
#include <ostream>
#include <vamp-sdk/Plugin.h>

using std::string;
using std::vector;
using std::cout;
using std::endl;

class AttackStartEndTimes : public Vamp::Plugin
{
public:
    AttackStartEndTimes(float inputSampleRate);
    virtual ~AttackStartEndTimes();

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

	vector<float> m_rms;
	vector<Vamp::RealTime> m_timestamps;
};



#endif // _ATTACKSTARTENDTIMES_H_