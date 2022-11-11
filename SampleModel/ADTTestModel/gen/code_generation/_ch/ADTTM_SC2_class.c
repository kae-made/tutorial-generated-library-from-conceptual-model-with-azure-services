/*----------------------------------------------------------------------------
 * File:  ADTTM_SC2_class.c
 *
 * Class:       SubClass2  (SC2)
 * Component:   ADTTM
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "ADTTestModel_sys_types.h"
#include "ADTTM_STR_bridge.h"
#include "ADTTM_classes.h"


/*
 * Statically allocate space for the instance population for this class.
 * Allocate space for the class instance and its attribute values.
 * Depending upon the collection scheme, allocate containoids (collection
 * nodes) for gathering instances into free and active extents.
 */
static Escher_SetElement_s ADTTM_SC2_container[ ADTTM_SC2_MAX_EXTENT_SIZE ];
static ADTTM_SC2 ADTTM_SC2_instances[ ADTTM_SC2_MAX_EXTENT_SIZE ];
Escher_Extent_t pG_ADTTM_SC2_extent = {
  {0}, {0}, &ADTTM_SC2_container[ 0 ],
  (Escher_iHandle_t) &ADTTM_SC2_instances,
  sizeof( ADTTM_SC2 ), 0, ADTTM_SC2_MAX_EXTENT_SIZE
  };

