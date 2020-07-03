// Script File

class ActionGetPlayerDescription : ActionInteractBase
{
	
	void ActionGetPlayerDescription()
	{
		m_CommandUID 	= DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask 	= DayZPlayerConstants.STANCEMASK_ALL;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}
	
	override bool IsInstant()
	{
		return true;
	}
	
	override void CreateConditionComponents()
	{
		m_ConditionTarget 	= new CCTMan( UAMaxDistances.DEFAULT );
		m_ConditionItem		= new CCINone;
	}
	
	override string GetText()
	{
		return "Inspect player";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		auto pb_target = PlayerBase.Cast( target.GetObject() );
		if ( pb_target && pb_target.IsAlive() )
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	
	override void OnStartServer( ActionData action_data )
	{
		auto pb_player = action_data.m_Player;
		auto pb_target = PlayerBase.Cast( action_data.m_Target.GetObject() );
		
		auto description = "Перед Вами ";
		description += ( pb_target.get_description() + "\n" );
		
		if ( pb_target.FindAttachmentBySlotName( "Headgear" ) == null ) 
		{
			description += ( pb_target.get_helm_slot_desc() + "\n" );
		}
		else {}
		if ( pb_target.FindAttachmentBySlotName( "Eyewear" ) == null )
		{
			description += ( pb_target.get_gl_slot_desc() + "\n" );
		}
		else {}
		if ( pb_target.FindAttachmentBySlotName( "Mask" ) == null )
		{
			description += ( pb_target.get_mask_slot_desc() + "\n" );
		}
		else {}
		if ( pb_target.FindAttachmentBySlotName( "Body" ) == null )
		{
			description += ( pb_target.get_body_slot_desc() + "\n" );
		}
		else {}
		if ( pb_target.FindAttachmentBySlotName( "Gloves" ) == null )
		{
			description += ( pb_target.get_hand_slot_desc() + "\n" );
		}
		else {}
		if ( pb_target.FindAttachmentBySlotName( "Legs" ) == null )
		{
			description += ( pb_target.get_legs_slot_desc() + "\n" );
		}
		else {}
		if ( pb_target.FindAttachmentBySlotName( "Feet" ) == null )
		{
			description += ( pb_target.get_foot_slot_desc() + "\n" );
		}
		else {}
		
		g_log.trace( "Tried to send description: " + description, "OnExecuteServer" );
		GetRPCManager().SendRPC( "AlastorCustomPlayerDescription", "RPCShowDescriptionToPlayer", new Param1< string >( description ), false, pb_player.GetIdentity() );
	}
	
	override void OnStartClient( ActionData action_data )
	{
		auto pb_target = PlayerBase.Cast( action_data.m_Target.GetObject() );
		
		if ( pb_target )
		{
			action_data.m_Player.m_GetDescriptionLastTarget = pb_target;
		}
		else {}
	}

}