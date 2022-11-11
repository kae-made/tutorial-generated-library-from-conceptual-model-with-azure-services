/*----------------------------------------------------------------------------
 * File:  ADTTM_classes.h
 *
 * This file defines the object type identification numbers for all classes
 * in the component:  ADTTM
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef ADTTM_CLASSES_H
#define ADTTM_CLASSES_H

#ifdef	__cplusplus
extern	"C"	{
#endif

/*
 * Initialization services for component:  ADTTM
 */
extern Escher_Extent_t * const ADTTM_class_info[];
extern const EventTaker_t ADTTM_EventDispatcher[];
void ADTTM_execute_initialization( void );

#define ADTTM_STATE_MODELS 2
/* Define constants to map to class numbers.  */
#define ADTTM_LD_CLASS_NUMBER 0
#define ADTTM_W_CLASS_NUMBER 1
#define ADTTM_TE_CLASS_NUMBER 2
#define ADTTM_ME_CLASS_NUMBER 3
#define ADTTM_OOD_CLASS_NUMBER 4
#define ADTTM_TS_CLASS_NUMBER 5
#define ADTTM_SC1_CLASS_NUMBER 6
#define ADTTM_SC2_CLASS_NUMBER 7
#define ADTTM_MML_CLASS_NUMBER 8
#define ADTTM_MAX_CLASS_NUMBERS 9

/* Provide a map of classes to task numbers.  */
#define ADTTM_TASK_NUMBERS  0, 0

#define ADTTM_class_dispatchers\
  ADTTM_LD_Dispatch,\
  ADTTM_W_Dispatch

/* Provide definitions of the shapes of the class structures.  */

typedef struct ADTTM_LD ADTTM_LD;
typedef struct ADTTM_W ADTTM_W;
typedef struct ADTTM_TE ADTTM_TE;
typedef struct ADTTM_ME ADTTM_ME;
typedef struct ADTTM_OOD ADTTM_OOD;
typedef struct ADTTM_TS ADTTM_TS;
typedef struct ADTTM_SC1 ADTTM_SC1;
typedef struct ADTTM_SC2 ADTTM_SC2;
typedef struct ADTTM_MML ADTTM_MML;

/* union of class declarations so we may derive largest class size */
#define ADTTM_CLASS_U \
  char ADTTM_dummy;\

/*
 * UML Domain Functions (Synchronous Services)
 */
void ADTTM_ClearInstances( void );
void ADTTM_TestExternalEntity( void );
void ADTTM_TestInitialize( void );
void ADTTM_TestSelectInstances( void );
void ADTTM_TestSelectRelated( void );

#include "ADTTM_STR_bridge.h"
#include "ADTTM.h"
#include "ADTTM_TE_class.h"
#include "ADTTM_ME_class.h"
#include "ADTTM_LD_class.h"
#include "ADTTM_OOD_class.h"
#include "ADTTM_TS_class.h"
#include "ADTTM_SC1_class.h"
#include "ADTTM_SC2_class.h"
#include "ADTTM_MML_class.h"
#include "ADTTM_W_class.h"
/*
 * roll-up of all events (with their parameters) for component ADTTM
 */
typedef union {
  ADTTM_LD_Events_u ADTTM_LD_Events_u_namespace;
  ADTTM_W_Events_u ADTTM_W_Events_u_namespace;
} ADTTM_DomainEvents_u;

#ifdef	__cplusplus
}
#endif
#endif  /* ADTTM_CLASSES_H */
