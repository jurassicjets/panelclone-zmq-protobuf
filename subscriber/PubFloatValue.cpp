#include "PubFloatValue.hpp"

#include "DatarefSubscriber.hpp"

extern "C" 
int PubFloatValue_find(PubFloatValue *dr, const char *dr_name) {
    bool success = DatarefSubscriber::getInstance().FindFloatValue(dr, std::string(dr_name));

    return (success);
}

extern "C" 
float PubFloatValue_getf(const PubFloatValue *dr) {
    assert(dr);
    float val = DatarefSubscriber::getInstance().GetFloatValue(dr->index);
    return val;
}
extern "C"
void PubFloatValue_setf(const PubFloatValue *dr, float val) {
    assert(dr);
    DatarefSubscriber::getInstance().SendDrefWrite(dr->index, val);
}

extern "C"
void PubCommand_send(const char *cmd, PubCommandAction action) {
    assert(cmd);
    DatarefSubscriber::getInstance().SendCommand(std::string(cmd),
        (panelclone::CommandEvent::Action)action);
}
