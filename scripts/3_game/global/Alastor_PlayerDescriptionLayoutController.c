// Script File

class Alastor_PlayerDescriptionLayoutController
{
	
	//-------------------------------------------------------------------------------
	
	void Alastor_PlayerDescriptionLayoutController()
	{
		create_layout();
		add_text_layout();
	}
	
	//-------------------------------------------------------------------------------
	
	void start_layout()
	{
		g_log.trace( "Layout started", "start_layout" );
		_layout.Show( true );
	}
	void start_layout( int sec )
	{
		start_layout();
		shutdown_layout_on_timer( sec );		
	}
	
	//-------------------------------------------------------------------------------
		
	void set_text_layout( string text_layout_text )
	{
		g_log.trace( "Layout text set to: " + text_layout_text, "set_text_layout" );
		_text_layout.SetText( text_layout_text );
	}
	
	//-------------------------------------------------------------------------------
	
	void shutdown_layout()
	{
		g_log.trace( "Layout shut down", "shutdown_layout" );
		_layout.Show( false );
		_is_timer_set = false;
	}
	void shutdown_layout_on_timer( int sec )
	{
		if ( !_is_timer_set )
		{
			g_log.trace( "Layout shutdown set on timer", "shutdown_layout_on_timer" );
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( shutdown_layout, sec * 1000, false );
			_is_timer_set = true;
		}
		else 
		{
			g_log.trace( "Timer was already set", "shutdown_layout_on_timer" );
		}
	}
	
	//-------------------------------------------------------------------------------
	
	protected void create_layout()
	{
		_layout = GetGame().GetWorkspace().CreateWidgets( _main_layout_path );
		if ( _layout != null )
		{
			g_log.trace( "Created layout", "create_layout" );
		}
		else 
		{
			g_log.error( "Failed to create layout [" + _main_layout_path + "]", "create_layout" ); 
		}
		shutdown_layout(); 		
	}
	
	protected void add_text_layout()
	{
		_text_layout = TextWidget.Cast( _layout.FindAnyWidget( _text_layout_name ) );
		if ( _text_layout != null )
		{
			g_log.trace( "Created text layout", "add_text_layout" );
		}
		else 
		{
			g_log.error( "Failed to create text layout", "add_text_layout" );
		}
	}
	
	//-------------------------------------------------------------------------------
	
	protected bool			_is_timer_set 		= false;
	protected const string 	_main_layout_path 	= "AlastorCustomPlayerDescription/gui/layouts/PlayerDescription/main.layout";
	protected const string	_text_layout_name	= "Description";
	protected Widget 		_layout;
	protected TextWidget	_text_layout;
	
}