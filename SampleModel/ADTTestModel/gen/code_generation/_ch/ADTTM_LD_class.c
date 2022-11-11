/*----------------------------------------------------------------------------
 * File:  ADTTM_LD_class.c
 *
 * Class:       Lief Device  (LD)
 * Component:   ADTTM
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "ADTTestModel_sys_types.h"
#include "ADTTM_STR_bridge.h"
#include "ADTTM_classes.h"

/*
 * instance operation:  Command
 */
void
ADTTM_LD_op_Command( ADTTM_LD * self, c_t p_order[ESCHER_SYS_MAX_STRING_LEN] )
{

}

/*
 * instance operation:  MeasureEnvironment
 */
void
ADTTM_LD_op_MeasureEnvironment( ADTTM_LD * self)
{

}

/*
 * instance operation:  CommandWithResult
 */
c_t *
ADTTM_LD_op_CommandWithResult( ADTTM_LD * self, c_t A0xtumlsret[ESCHER_SYS_MAX_STRING_LEN], const i_t p_mode, c_t p_operation[ESCHER_SYS_MAX_STRING_LEN] )
{
  c_t result[ESCHER_SYS_MAX_STRING_LEN];
  /* ASSIGN result =  */
  XTUML_OAL_STMT_TRACE( 1, "ASSIGN result = " );
  Escher_strcpy( result, "" );
  /* RETURN result */
  XTUML_OAL_STMT_TRACE( 1, "RETURN result" );
  {c_t * xtumlOALrv = result;
  return Escher_strcpy( A0xtumlsret, xtumlOALrv );}
}

/*
 * RELATE ME TO LD ACROSS R2
 */
void
ADTTM_LD_R2_Link_measurement( ADTTM_ME * part, ADTTM_LD * form )
{
  if ( (part == 0) || (form == 0) ) {
    XTUML_EMPTY_HANDLE_TRACE( "LD", "ADTTM_LD_R2_Link_measurement" );
    return;
  }
  form->MiddleEntityId = part->MiddleEntityId;
  /* Note:  LD->ME[R2] not navigated */
  Escher_SetInsertElement( &part->LD_R2_measurement, (Escher_ObjectSet_s *) form );
}

/*
 * UNRELATE ME FROM LD ACROSS R2
 */
void
ADTTM_LD_R2_Unlink_measurement( ADTTM_ME * part, ADTTM_LD * form )
{
  if ( (part == 0) || (form == 0) ) {
    XTUML_EMPTY_HANDLE_TRACE( "LD", "ADTTM_LD_R2_Unlink_measurement" );
    return;
  }
  /* Note:  LD->ME[R2] not navigated */
  Escher_SetRemoveElement( &part->LD_R2_measurement, (Escher_ObjectSet_s *) form );
}

/*----------------------------------------------------------------------------
 * Operation action methods implementation for the following class:
 *
 * Class:      Lief Device  (LD)
 * Component:  ADTTM
 *--------------------------------------------------------------------------*/
/*
 * Statically allocate space for the instance population for this class.
 * Allocate space for the class instance and its attribute values.
 * Depending upon the collection scheme, allocate containoids (collection
 * nodes) for gathering instances into free and active extents.
 */
static Escher_SetElement_s ADTTM_LD_container[ ADTTM_LD_MAX_EXTENT_SIZE ];
static ADTTM_LD ADTTM_LD_instances[ ADTTM_LD_MAX_EXTENT_SIZE ];
Escher_Extent_t pG_ADTTM_LD_extent = {
  {0}, {0}, &ADTTM_LD_container[ 0 ],
  (Escher_iHandle_t) &ADTTM_LD_instances,
  sizeof( ADTTM_LD ), ADTTM_LD_STATE_1, ADTTM_LD_MAX_EXTENT_SIZE
  };
/*----------------------------------------------------------------------------
 * State and transition action implementations for the following class:
 *
 * Class:      Lief Device  (LD)
 * Component:  ADTTM
 *--------------------------------------------------------------------------*/

/*
 * State 1:  [Wait for Measure]
 */
static void ADTTM_LD_act1( ADTTM_LD *, const Escher_xtUMLEvent_t * const );
static void
ADTTM_LD_act1( ADTTM_LD * self, const Escher_xtUMLEvent_t * const event )
{
}

/*
 * State 2:  [Measured]
 */
static void ADTTM_LD_act2( ADTTM_LD *, const Escher_xtUMLEvent_t * const );
static void
ADTTM_LD_act2( ADTTM_LD * self, const Escher_xtUMLEvent_t * const event )
{
  /* self.MeasureEnvironment() */
  XTUML_OAL_STMT_TRACE( 1, "self.MeasureEnvironment()" );
  ADTTM_LD_op_MeasureEnvironment( self );
  /* GENERATE LD2:Measured() TO SELF */
  XTUML_OAL_STMT_TRACE( 1, "GENERATE LD2:Measured() TO SELF" );
  { Escher_xtUMLEvent_t * e = Escher_NewxtUMLEvent( self, &ADTTM_LDevent2c );
    Escher_SendSelfEvent( e );
  }
}

const Escher_xtUMLEventConstant_t ADTTM_LDevent1c = {
  ADTTM_DOMAIN_ID, ADTTM_LD_CLASS_NUMBER, ADTTM_LDEVENT1NUM,
  ESCHER_IS_INSTANCE_EVENT };
const Escher_xtUMLEventConstant_t ADTTM_LDevent2c = {
  ADTTM_DOMAIN_ID, ADTTM_LD_CLASS_NUMBER, ADTTM_LDEVENT2NUM,
  ESCHER_IS_INSTANCE_EVENT };


/*
 * State-Event Matrix (SEM)
 * Row index is object (MC enumerated) current state.
 * Row zero is the uninitialized state (e.g., for creation event transitions).
 * Column index is (MC enumerated) state machine events.
 */
static const Escher_SEMcell_t ADTTM_LD_StateEventMatrix[ 2 + 1 ][ 2 ] = {
  /* row 0:  uninitialized state (for creation events) */
  { EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN },
  /* row 1:  ADTTM_LD_STATE_1 (Wait for Measure) */
  { ADTTM_LD_STATE_2, EVENT_CANT_HAPPEN },
  /* row 2:  ADTTM_LD_STATE_2 (Measured) */
  { EVENT_CANT_HAPPEN, ADTTM_LD_STATE_1 }
};

  /*
   * Array of pointers to the class state action procedures.
   * Index is the (MC enumerated) number of the state action to execute.
   */
  static const StateAction_t ADTTM_LD_acts[ 3 ] = {
    (StateAction_t) 0,
    (StateAction_t) ADTTM_LD_act1,  /* Wait for Measure */
    (StateAction_t) ADTTM_LD_act2  /* Measured */
  };

  /*
   * Array of string names of the state machine names.
   * Index is the (MC enumerated) number of the state.
   */
  static const c_t * const state_name_strings[ 3 ] = {
    "",
    "Wait for Measure",
    "Measured"
  };

/*
 * instance state machine event dispatching
 */
void
ADTTM_LD_Dispatch( Escher_xtUMLEvent_t * event )
{
  Escher_iHandle_t instance = GetEventTargetInstance( event );
  Escher_EventNumber_t event_number = GetOoaEventNumber( event );
  Escher_StateNumber_t current_state;
  Escher_StateNumber_t next_state;
  if ( 0 != instance ) {
    current_state = instance->current_state;
    if ( current_state > 2 ) {
      /* instance validation failure (object deleted while event in flight) */
      UserEventNoInstanceCallout( event_number );
    } else {
      next_state = ADTTM_LD_StateEventMatrix[ current_state ][ event_number ];
      if ( next_state <= 2 ) {
        STATE_TXN_START_TRACE( "LD", current_state, state_name_strings[ current_state ] );
        /* Update the current state and execute the state action.  */
        instance->current_state = next_state;
        ( *ADTTM_LD_acts[ next_state ] )( instance, event );
        STATE_TXN_END_TRACE( "LD", next_state, state_name_strings[ next_state ] );
      } else if ( next_state == EVENT_CANT_HAPPEN ) {
          /* event cant happen */
          UserEventCantHappenCallout( current_state, next_state, event_number );
          STATE_TXN_CH_TRACE( "LD", current_state );
      } else {
        /* empty else */
      }
    }
  }
}

