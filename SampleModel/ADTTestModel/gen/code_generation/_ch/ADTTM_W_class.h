/*----------------------------------------------------------------------------
 * File:  ADTTM_W_class.h
 *
 * Class:       Worker  (W)
 * Component:   ADTTM
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef ADTTM_W_CLASS_H
#define ADTTM_W_CLASS_H

#ifdef	__cplusplus
extern	"C"	{
#endif

/*
 * Structural representation of application analysis class:
 *   Worker  (W)
 */
struct ADTTM_W {
  Escher_StateNumber_t current_state;
  /* application analysis class attributes */
  Escher_UniqueID_t WId;  /* * WId */
  Escher_UniqueID_t LiefDeviceId;  /* - LiefDeviceId (R6) */
  /* relationship storage */
  ADTTM_LD * LD_R6_target;
};

void ADTTM_W_R6_Link( ADTTM_LD *, ADTTM_W * );
void ADTTM_W_R6_Unlink( ADTTM_LD *, ADTTM_W * );

#define ADTTM_W_MAX_EXTENT_SIZE 10
extern Escher_Extent_t pG_ADTTM_W_extent;

/*
 * creation event:  W1:'Create'
 */
typedef struct {
  EVENT_BASE_ATTRIBUTE_LIST         /* base attributes of all event classes */
  Escher_UniqueID_t p_targetId; /* targetId */
} ADTTM_Wevent1;
extern const Escher_xtUMLEventConstant_t ADTTM_Wevent1c;
/*
 * instance event:  W2:'Start'
 * warning:  Event is not used in application - no code generated.
 */
/*
 * instance event:  W3:'Done'
 */
typedef struct {
  EVENT_BASE_ATTRIBUTE_LIST         /* base attributes of all event classes */
  /* Note:  no supplemental data for this event */
} ADTTM_Wevent3;
extern const Escher_xtUMLEventConstant_t ADTTM_Wevent3c;
/*
 * union of events targeted towards 'W' state machine
 */
typedef union {
  ADTTM_Wevent1 w1_1;  
  ADTTM_Wevent3 w3_2;  
} ADTTM_W_Events_u;
/*
 * enumeration of state model states for class
 */
#define ADTTM_W_STATE_1 1  /* state [1]:  (Created) */
#define ADTTM_W_STATE_2 2  /* state [2]:  (Working) */
#define ADTTM_W_STATE_3 3  /* state [3]:  (Completed) */
/*
 * enumeration of state model event numbers
 */
#define ADTTM_WEVENT1NUM 0  /* W1:'Create' */
#define ADTTM_WEVENT3NUM 1  /* W3:'Done' */
extern void ADTTM_W_Dispatch( Escher_xtUMLEvent_t * );

#ifdef	__cplusplus
}
#endif

#endif  /* ADTTM_W_CLASS_H */
