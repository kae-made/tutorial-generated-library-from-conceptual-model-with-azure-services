/*----------------------------------------------------------------------------
 * File:  ADTTM_TS_class.c
 *
 * Class:       TestSuper  (TS)
 * Component:   ADTTM
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "ADTTestModel_sys_types.h"
#include "ADTTM_STR_bridge.h"
#include "ADTTM_classes.h"


/* Accessors to TS[R4] subtypes */

/*
 * Statically allocate space for the instance population for this class.
 * Allocate space for the class instance and its attribute values.
 * Depending upon the collection scheme, allocate containoids (collection
 * nodes) for gathering instances into free and active extents.
 */
static Escher_SetElement_s ADTTM_TS_container[ ADTTM_TS_MAX_EXTENT_SIZE ];
static ADTTM_TS ADTTM_TS_instances[ ADTTM_TS_MAX_EXTENT_SIZE ];
Escher_Extent_t pG_ADTTM_TS_extent = {
  {0}, {0}, &ADTTM_TS_container[ 0 ],
  (Escher_iHandle_t) &ADTTM_TS_instances,
  sizeof( ADTTM_TS ), 0, ADTTM_TS_MAX_EXTENT_SIZE
  };

