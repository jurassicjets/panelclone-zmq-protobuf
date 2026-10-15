#ifndef _PUBFLOATVALUE_HPP_
#define _PUBFLOATVALUE_HPP_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct PubFloatValue_s
{
    int index;
    int dref_index;
    float value;
} PubFloatValue;

int PubFloatValue_find(PubFloatValue *dr, const char *dr_name);

float PubFloatValue_getf(const PubFloatValue *dr);

/* Panel -> sim input. Values match panelclone::CommandEvent::Action. */
typedef enum {
    PUB_CMD_ONCE = 0,
    PUB_CMD_BEGIN = 1,
    PUB_CMD_END = 2
} PubCommandAction;

/* Write a published dataref (by its published index) on the sim. */
void PubFloatValue_setf(const PubFloatValue *dr, float val);

/* Run an X-Plane command on the sim. */
void PubCommand_send(const char *cmd, PubCommandAction action);

#ifdef __cplusplus
}
#endif

#endif // #ifndefine _PUBFLOATVALUE_HPP_