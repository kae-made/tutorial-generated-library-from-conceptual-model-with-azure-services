/*----------------------------------------------------------------------------
 * File:  ADTTM_W_class.c
 *
 * Class:       Worker  (W)
 * Component:   ADTTM
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "ADTTestModel_sys_types.h"
#include "ADTTM_STR_bridge.h"
#include "ADTTM_classes.h"


/*
 * RELATE LD TO W ACROSS R6
 */
void
ADTTM_W_R6_Link( ADTTM_LD * part, ADTTM_W * form )
{
  if ( (part == 0) || (form == 0) ) {
    XTUML_EMPTY_HANDLE_TRACE( "W", "ADTTM_W_R6_Link" );
    return;
  }
  form->LiefDeviceId = part->LiefDeviceId;
  form->LD_R6_target = part;
  /* Note:  LD->W[R6] not navigated */
}

/*
 * UNRELATE LD FROM W ACROSS R6
 */
void
ADTTM_W_R6_Unlink( ADTTM_LD * part, ADTTM_W * form )
{
  if ( (part == 0) || (form == 0) ) {
    XTUML_EMPTY_HANDLE_TRACE( "W", "ADTTM_W_R6_Unlink" );
    return;
  }
  form->LiefDeviceId = 0;
  form->LD_R6_target = 0;
  /* Note:  LD->W[R6] not navigated */
}
/*
 * Statically allocate space for the instance population for this class.
 * Allocate space for the class instance and its attribute values.
 * Depending upon the collection scheme, allocate containoids (collection
 * nodes) for gathering instances into free and active extents.
 */
static Escher_SetElement_s ADTTM_W_container[ ADTTM_W_MAX_EXTENT_SIZE ];
static ADTTM_W ADTTM_W_instances[ ADTTM_W_MAX_EXTENT_SIZE ];
Escher_Extent_t pG_ADTTM_W_extent = {
  {0}, {0}, &ADTTM_W_container[ 0 ],
  (Escher_iHandle_t) &ADTTM_W_instances,
  sizeof( ADTTM_W ), ADTTM_W_STATE_1, ADTTM_W_MAX_EXTENT_SIZE
  };
/*----------------------------------------------------------------------------
 * State and transition action implementations for the following class:
 *
 * Class:      Worker  (W)
 * Component:  ADTTM
 *--------------------------------------------------------------------------*/

/*
 * State 1:  [Created]
 */
static void ADTTM_W_act1( ADTTM_W *, const Escher_xtUMLEvent_t * const );
static void
ADTTM_W_act1( ADTTM_W * self, const Escher_xtUMLEvent_t * const event )
{
  ADTTM_Wevent1 * rcvd_evt = (ADTTM_Wevent1 *) event;
  ADTTM_LD * ld=0;
  /* SELECT any ld FROM INSTANCES OF LD WHERE SELECTED.LiefDeviceId == PARAM.targetId */
  XTUML_OAL_STMT_TRACE( 1, "SELECT any ld FROM INSTANCES OF LD WHERE SELECTED.LiefDeviceId == PARAM.targetId" );
  ld = 0;
  { ADTTM_LD * selected;
    Escher_Iterator_s iterldADTTM_LD;
    Escher_IteratorReset( &iterldADTTM_LD, &pG_ADTTM_LD_extent.active );
    while ( (selected = (ADTTM_LD *) Escher_IteratorNext( &iterldADTTM_LD )) != 0 ) {
      if ( ((ADTTM_LD *)xtUML_detect_empty_handle( selected, "LD", "SELECTED.LiefDeviceId" ))->LiefDeviceId == rcvd_evt->p_targetId ) {
        ld = selected;
        break;
      }
    }
  }
  /* IF ( not_empty ld ) */
  XTUML_OAL_STMT_TRACE( 1, "IF ( not_empty ld )" );
  if ( ( 0 != ld ) ) {
    /* RELATE SELF TO ld ACROSS R6 */
    XTUML_OAL_STMT_TRACE( 2, "RELATE SELF TO ld ACROSS R6" );
    ADTTM_W_R6_Link( ld, self );
  }
}

/*
 * State 2:  [Working]
 */
static void ADTTM_W_act2( ADTTM_W *, const Escher_xtUMLEvent_t * const );
static void
ADTTM_W_act2( ADTTM_W * self, const Escher_xtUMLEvent_t * const event )
{
  ADTTM_LD * ld=0;
  /* SELECT one ld RELATED BY self->LD[R6.target] */
  XTUML_OAL_STMT_TRACE( 1, "SELECT one ld RELATED BY self->LD[R6.target]" );
  ld = ( 0 != self ) ? self->LD_R6_target : 0;
  /* GENERATE LD1:Measure() TO ld */
  XTUML_OAL_STMT_TRACE( 1, "GENERATE LD1:Measure() TO ld" );
  { Escher_xtUMLEvent_t * e = Escher_NewxtUMLEvent( ld, &ADTTM_LDevent1c );
    Escher_SendEvent( e );
  }
  /* GENERATE W3:Done() TO SELF */
  XTUML_OAL_STMT_TRACE( 1, "GENERATE W3:Done() TO SELF" );
  { Escher_xtUMLEvent_t * e = Escher_NewxtUMLEvent( self, &ADTTM_Wevent3c );
    Escher_SendSelfEvent( e );
  }
}

/*
 * State 3:  [Completed]
 */
static void ADTTM_W_act3( ADTTM_W *, const Escher_xtUMLEvent_t * const );
static void
ADTTM_W_act3( ADTTM_W * self, const Escher_xtUMLEvent_t * const event )
{
  ADTTM_LD * ld=0;
  /* SELECT one ld RELATED BY self->LD[R6.target] */
  XTUML_OAL_STMT_TRACE( 1, "SELECT one ld RELATED BY self->LD[R6.target]" );
  ld = ( 0 != self ) ? self->LD_R6_target : 0;
  /* UNRELATE ld FROM self ACROSS R6 */
  XTUML_OAL_STMT_TRACE( 1, "UNRELATE ld FROM self ACROSS R6" );
  ADTTM_W_R6_Unlink( ld, self );
}

const Escher_xtUMLEventConstant_t ADTTM_Wevent1c = {
  ADTTM_DOMAIN_ID, ADTTM_W_CLASS_NUMBER, ADTTM_WEVENT1NUM,
  ESCHER_IS_CREATION_EVENT };

const Escher_xtUMLEventConstant_t ADTTM_Wevent3c = {
  ADTTM_DOMAIN_ID, ADTTM_W_CLASS_NUMBER, ADTTM_WEVENT3NUM,
  ESCHER_IS_INSTANCE_EVENT };


/*
 * State-Event Matrix (SEM)
 * Row index is object (MC enumerated) current state.
 * Row zero is the uninitialized state (e.g., for creation event transitions).
 * Column index is (MC enumerated) state machine events.
 */
static const Escher_SEMcell_t ADTTM_W_StateEventMatrix[ 3 + 1 ][ 2 ] = {
  /* row 0:  uninitialized state (for creation events) */
  { ADTTM_W_STATE_1, EVENT_CANT_HAPPEN },
  /* row 1:  ADTTM_W_STATE_1 (Created) */
  { EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN },
  /* row 2:  ADTTM_W_STATE_2 (Working) */
  { EVENT_CANT_HAPPEN, ADTTM_W_STATE_3 },
  /* row 3:  ADTTM_W_STATE_3 (Completed) */
  { EVENT_CANT_HAPPEN, EVENT_CANT_HAPPEN }
};

  /*
   * Array of pointers to the class state action procedures.
   * Index is the (MC enumerated) number of the state action to execute.
   */
  static const StateAction_t ADTTM_W_acts[ 4 ] = {
    (StateAction_t) 0,
    (StateAction_t) ADTTM_W_act1,  /* Created */
    (StateAction_t) ADTTM_W_act2,  /* Working */
    (StateAction_t) ADTTM_W_act3  /* Completed */
  };

  /*
   * Array of string names of the state machine names.
   * Index is the (MC enumerated) number of the state.
   */
  static const c_t * const state_name_strings[ 4 ] = {
    "",
    "Created",
    "Working",
    "Completed"
  };

/*
 * instance state machine event dispatching
 */
void
ADTTM_W_Dispatch( Escher_xtUMLEvent_t * event )
{
  Escher_iHandle_t instance;
  Escher_EventNumber_t event_number = GetOoaEventNumber( event );
  Escher_StateNumber_t current_state;
  Escher_StateNumber_t next_state;
  if ( 0 != GetIsCreationEvent( event ) ) {
    instance = Escher_CreateInstance( ADTTM_DOMAIN_ID, ADTTM_W_CLASS_NUMBER );
    if ( 0 != instance ) {
      ADTTM_W * i = (ADTTM_W *) instance;
i->WId = Escher_ID_factory();
      instance->current_state = UNINITIALIZED_STATE;
      SetEventTargetInstance( event, instance );
    } else {
      /* Instance allocation failure - USER RECOVERY LOGIC IS TBD */
      UserEventNoInstanceCallout( 0 );
    }
  } else {
    instance = GetEventTargetInstance( event );
  }
  if ( 0 != instance ) {
    current_state = instance->current_state;
    if ( current_state > 3 ) {
      /* instance validation failure (object deleted while event in flight) */
      UserEventNoInstanceCallout( event_number );
    } else {
      next_state = ADTTM_W_StateEventMatrix[ current_state ][ event_number ];
      if ( next_state <= 3 ) {
        STATE_TXN_START_TRACE( "W", current_state, state_name_strings[ current_state ] );
        /* Update the current state and execute the state action.  */
        instance->current_state = next_state;
        ( *ADTTM_W_acts[ next_state ] )( instance, event );
        STATE_TXN_END_TRACE( "W", next_state, state_name_strings[ next_state ] );

        /* Self deletion state transition? */
        if ( next_state == ADTTM_W_STATE_3 ) {          Escher_DeleteInstance( instance, ADTTM_DOMAIN_ID, ADTTM_W_CLASS_NUMBER );
        }
      } else if ( next_state == EVENT_CANT_HAPPEN ) {
          /* event cant happen */
          UserEventCantHappenCallout( current_state, next_state, event_number );
          STATE_TXN_CH_TRACE( "W", current_state );
      } else {
        /* empty else */
      }
    }
  }
}

