class CfgPatches
{
	class AlastorCustomPlayerDescription
	{
		units[]				= {};
		weapons[]			= {};
		requiredVersion		= 0.1;
		requiredAddons[]	= { "DZ_Data", "AlastorLogger", "AlastorPlayerInfoExtender" };
	};
};

class CfgMods
{
	class CustomPlayerDescription
	{
	    type 			= "mod";
		name 			= "AlastorCustomPlayerDescription";
		author 			= "Alastor";
		authorID 		= "76561198052045611";
	    dependencies[] 	= { "Game", "World" };
		
	    class defs
	    {

			class gameScriptModule
            {
                value	= "";
                files[] = { "AlastorCustomPlayerDescription/scripts/3_game" };
            };
			
			class worldScriptModule		
            {
                value	= "";
                files[] = { "AlastorCustomPlayerDescription/scripts/4_world" };
            };
			
        };
    };
};