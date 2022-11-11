/*----------------------------------------------------------------------------
 * File:  ADTTM_LD_class.h
 *
 * Class:       Lief Device  (LD)
 * Component:   ADTTM
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef ADTTM_LD_CLASS_H
#define ADTTM_LD_CLASS_H

#ifdef	__cplusplus
extern	"C"	{
#endif

/*
 * Structural representation of application analysis class:
 *   Lief Device  (LD)
 */
struct ADTTM_LD {
  Escher_StateNumber_t current_state;
  /* application analysis class attributes */
  Escher_UniqueID_t LiefDeviceId;  /* * LiefDeviceId */
  ADTTM_sdt_EnvironmentPhysicalQuantities Environment;  /* - Environment */
  i_t Number;  /* *2 Number */
  Escher_UniqueID_t MiddleEntityId;  /* *2 MiddleEntityId (R2) */
  i_t RequestInterval;  /* - RequestInterval */
  i_t CurrentInterval;  /* - CurrentInterval */
  c_t DeviceStatus[ESCHER_SYS_MAX_STRING_LEN];  /* - DeviceStatus */
  /* relationship storage */
  /* Note:  No storage needed for LD->ME[R2] */
  ADTTM_OOD * OOD_R3_right;
  ADTTM_OOD * OOD_R3_left;
  ADTTM_MML * MML_R5;
  /* Note:  No storage needed for LD->W[R6] */
};
void ADTTM_LD_op_Command( ADTTM_LD *, c_t[ESCHER_SYS_MAX_STRING_LEN] );
void ADTTM_LD_op_MeasureEnvironment( ADTTM_LD * );
c_t * ADTTM_LD_op_CommandWithResult( ADTTM_LD *, c_t[ESCHER_SYS_MAX_STRING_LEN], const i_t, c_t[ESCHER_SYS_MAX_STRING_LEN] );
void ADTTM_LD_R2_Link_measurement( ADTTM_ME *, ADTTM_LD * );
void ADTTM_LD_R2_Unlink_measurement( ADTTM_ME *, ADTTM_LD * );

#define ADTTM_LD_MAX_EXTENT_SIZE 10
extern Escher_Extent_t pG_ADTTM_LD_extent;

/*
 * instance event:  LD1:'Measure'
 */
typedef struct {
  EVENT_BASE_ATTRIBUTE_LIST         /* base attributes of all event classes */
  /* Note:  no supplemental data for this event */
} ADTTM_LDevent1;
extern const Escher_xtUMLEventConstant_t ADTTM_LDevent1c;
/*
 * instance event:  LD2:'Measured'
 */
typedef struct {
  EVENT_BASE_ATTRIBUTE_LIST         /* base attributes of all event classes */
  /* Note:  no supplemental data for this event */
} ADTTM_LDevent2;
extern const Escher_xtUMLEventConstant_t ADTTM_LDevent2c;
/*
 * union of events targeted towards 'LD' state machine
 */
typedef union {
  ADTTM_LDevent1 ld1_1;  
  ADTTM_LDevent2 ld2_2;  
} ADTTM_LD_Events_u;
/*
 * enumeration of state model states for class
 */
#define ADTTM_LD_STATE_1 1  /* state [1]:  (Wait for Measure) */
#define ADTTM_LD_STATE_2 2  /* state [2]:  (Measured) */
/*
 * enumeration of state model event numbers
 */
#define ADTTM_LDEVENT1NUM 0  /* LD1:'Measure' */
#define ADTTM_LDEVENT2NUM 1  /* LD2:'Measured' */
extern void ADTTM_LD_Dispatch( Escher_xtUMLEvent_t * );

#ifdef	__cplusplus
}
#endif

#endif  /* ADTTM_LD_CLASS_H */
