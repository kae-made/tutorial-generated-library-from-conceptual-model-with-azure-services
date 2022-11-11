/*----------------------------------------------------------------------------
 * File:  ADTTM_MML_class.c
 *
 * Class:       Mapping Middel To Lief  (MML)
 * Component:   ADTTM
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "ADTTestModel_sys_types.h"
#include "ADTTM_STR_bridge.h"
#include "ADTTM_classes.h"

/* Note:  Link ME to LD across R5 using MML not needed.  */

/* Note:  Unlink ME from LD across R5 using MML not needed.  */
/*
 * Statically allocate space for the instance population for this class.
 * Allocate space for the class instance and its attribute values.
 * Depending upon the collection scheme, allocate containoids (collection
 * nodes) for gathering instances into free and active extents.
 */
static Escher_SetElement_s ADTTM_MML_container[ ADTTM_MML_MAX_EXTENT_SIZE ];
static ADTTM_MML ADTTM_MML_instances[ ADTTM_MML_MAX_EXTENT_SIZE ];
Escher_Extent_t pG_ADTTM_MML_extent = {
  {0}, {0}, &ADTTM_MML_container[ 0 ],
  (Escher_iHandle_t) &ADTTM_MML_instances,
  sizeof( ADTTM_MML ), 0, ADTTM_MML_MAX_EXTENT_SIZE
  };

