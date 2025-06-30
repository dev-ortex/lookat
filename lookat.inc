/*

                    ooooo      ooo       .o.       ooooooooooooo ooooo oooooo     oooo       .o.        .oooooo..o 
                    `888b.     `8'      .888.      8'   888   `8 `888'  `888.     .8'       .888.      d8P'    `Y8 
                    8 `88b.    8      .8"888.          888       888    `888.   .8'       .8"888.     Y88bo.      
                    8   `88b.  8     .8' `888.         888       888     `888. .8'       .8' `888.     `"Y8888o.  
                    8     `88b.8    .88ooo8888.        888       888      `888.8'       .88ooo8888.        `"Y88b 
                    8       `888   .8'     `888.       888       888       `888'       .8'     `888.  oo     .d8P 
                    o8o        `8  o88o     o8888o     o888o     o888o       `8'       o88o     o8888o 8""88888P'  

		native bool:IsPointLookingAtPoint(playerid, Float:x, Float:y, Float:z, Float:range = MAX_RANGE_DISTANCE);
		native bool:IsPlayerLookingAtPlayer(playerid, targetid, Float:range = MAX_RANGE_DISTANCE);
		native bool:IsPlayerLookingAtVehicle(playerid, targetid, Float:range = MAX_RANGE_DISTANCE);
		native bool:IsPlayerLookingAtObject(playerid, targetid, Float:range = MAX_RANGE_DISTANCE);
		native bool:IsPlayerLookingAtActor(playerid, targetid, Float:range = MAX_RANGE_DISTANCE);
		native bool:IsPlayerLookingAt(playerid, E_LOOKAT_TYPE:type, targetid, Float:range = MAX_RANGE_DISTANCE);
                                                                                          
*/

#if defined _lookat_included
	#endinput
#endif
#define _lookat_included

			// Definers
static const 		Float:MAX_RANGE_DISTANCE = 1.0;
static const 		Float:MAX_SCALE_DISTANCE = 5.0;

enum E_LOOKAT {
	E_LOOKAT_PLAYER,
	E_LOOKAT_VEHICLE,
	E_LOOKAT_OBJECT,
	E_LOOKAT_ACTOR
};

enum E_LOOKAT_TYPE
{
    E_LOOKAT_PLAYER,
    E_LOOKAT_VEHICLE,
    E_LOOKAT_OBJECT,
    E_LOOKAT_ACTOR
};



/*

                    .oooooo..o ooooooooooooo   .oooooo.     .oooooo.   oooo    oooo  .oooooo..o
                    d8P'    `Y8 8'   888   `8  d8P'  `Y8b   d8P'  `Y8b  `888   .8P'  d8P'    `Y8
                    Y88bo.           888      888      888 888           888  d8'    Y88bo.     
                    `"Y8888o.       888      888      888 888           88888[       `"Y8888o. 
                        `"Y88b      888      888      888 888           888`88b.         `"Y88b
                    oo     .d8P      888      `88b    d88' `88b    ooo   888  `88b.  oo     .d8P
                    8""88888P'      o888o      `Y8bood8P'   `Y8bood8P'  o888o  o888o 8""88888P' 

*/

static stock GetPlayerViewDirection(playerid, Float:scale, &Float:x, &Float:y, &Float:z)
{
    new Float:camX, Float:camY, Float:camZ;
    new Float:posX, Float:posY, Float:posZ;

    GetPlayerCameraPos(playerid, camX, camY, camZ);
    GetPlayerCameraFrontVector(playerid, posX, posY, posZ);

    x = camX + posX * scale;
    y = camY + posY * scale;
    z = camZ + posZ * scale;
}

static stock bool:IsFloatBetween(Float:value, Float:center, Float:range = MAX_RANGE_DISTANCE)
{
    return (value >= (center - range) && value <= (center + range));
}

stock bool:IsPointLookingAtPoint(playerid, Float:x, Float:y, Float:z, Float:range = MAX_RANGE_DISTANCE)
{
    new Float:posX, Float:posY, Float:posZ;
    GetPlayerViewDirection(playerid, MAX_SCALE_DISTANCE, posX, posY, posZ);

    return IsFloatBetween(posX, x, range) && IsFloatBetween(posY, y, range) && IsFloatBetween(posZ, z, range);
}

stock bool:IsPlayerLookingAtPlayer(playerid, targetid, Float:range = MAX_RANGE_DISTANCE)
{
    new Float:posX, Float:posY, Float:posZ;
    GetPlayerViewDirection(playerid, MAX_SCALE_DISTANCE, posX, posY, posZ);

    return IsPointLookingAtPoint(targetid, range, posX, posY, posZ);
}

stock bool:IsPlayerLookingAtVehicle(playerid, targetid, Float:range = MAX_RANGE_DISTANCE)
{
    new Float:posX, Float:posY, Float:posZ;
    GetVehiclePos(targetid, posX, posY, posZ);

    return IsPointLookingAtPoint(playerid, posX, posY, posZ, range);
}

stock bool:IsPlayerLookingAtObject(playerid, targetid, Float:range = MAX_RANGE_DISTANCE)
{
    new Float:posX, Float:posY, Float:posZ;
    GetObjectPos(targetid, posX, posY, posZ);

    return IsPointLookingAtPoint(playerid, posX, posY, posZ, range);
}

stock bool:IsPlayerLookingAtActor(playerid, targetid, Float:range = MAX_RANGE_DISTANCE)
{
    new Float:posX, Float:posY, Float:posZ;
    GetActorPos(targetid, posX, posY, posZ);

    return IsPointLookingAtPoint(playerid, posX, posY, posZ, range);
}

stock bool:IsPlayerLookingAt(playerid, E_LOOKAT_TYPE:type, targetid, Float:range = MAX_RANGE_DISTANCE)
{
    new Float:x, Float:y, Float:z;
    switch (type) {
        case E_LOOKAT_PLAYER: GetPlayerPos(targetid,  x, y, z);
        case E_LOOKAT_VEHICLE: GetVehiclePos(targetid, x, y, z);
        case E_LOOKAT_OBJECT: GetObjectPos(targetid, x, y, z);
        case E_LOOKAT_ACTOR: GetActorPos(targetid, x, y, z);
        default: return false;
    }
    return IsPointLookingAtPoint(playerid, x, y, z, range);
}
