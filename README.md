# 👁️ LookAt

A Pawn include for checking whether a player is looking at another entity using camera direction. Ideal for interaction systems, NPC detection, immersive dialogues, and dynamic targeting.

---

## 📦 Installation

1. Download the latest version of `lookat.inc`.
2. Place the file inside your server’s `include/` folder.
3. Include it in your gamemode or filterscript:

```pawn
#include <lookat>
```

---

## ⚙️ Native Functions

```pawn
native bool:IsPointLookingAtPoint(playerid, Float:x, Float:y, Float:z, Float:range = MAX_RANGE_DISTANCE);
native bool:IsPlayerLookingAtPlayer(playerid, targetid, Float:range = MAX_RANGE_DISTANCE);
native bool:IsPlayerLookingAtVehicle(playerid, targetid, Float:range = MAX_RANGE_DISTANCE);
native bool:IsPlayerLookingAtObject(playerid, targetid, Float:range = MAX_RANGE_DISTANCE);
native bool:IsPlayerLookingAtActor(playerid, targetid, Float:range = MAX_RANGE_DISTANCE);
native bool:IsPlayerLookingAt(playerid, E_LOOKAT_TYPE:type, targetid, Float:range = MAX_RANGE_DISTANCE);
```

> \[!IMPORTANT]
>
> * `scale`: Distance forward from the camera to simulate a "line of sight".
> * `range`: How close the target must be to the center of view to be considered "looked at".

---

## 🧠 Entity Types

| ID | Type    |
| -- | ------- |
| E_LOOKAT_PLAYER   | Player  |
| E_LOOKAT_VEHICLE  | Vehicle |
| E_LOOKAT_OBJECT   | Object  |
| E_LOOKAT_ACTOR    | Actor   |
---

## 🧪 Example Usage

```pawn
CMD:interact(playerid)
{
    for (new i = 0; i < MAX_PLAYERS; i++) {
		if(!IsPlayerConnected(i)) continue;

        if (i != playerid && IsPlayerLookingAt(playerid, E_LOOKAT_PLAYER, i)) {
		SendClientMessage(playerid, -1, "Voce esta olhando para um jogador!");
        } 
    }

	for (new i = 0; i < MAX_VEHICLES; i++) {
		if(!IsValidVehicle(i)) continue;

		if (IsPlayerLookingAtVehicle(playerid, i)) {
			SendClientMessage(playerid, -1, "Voce esta olhando para o seu veiculo!");
		}
	}
    return 1;
}
```

---

## 📷 Demo Video

https://github.com/user-attachments/assets/d32f3a7f-6e6f-4fca-9c9e-1471a62e9869

---

## 🙌 Credits

* **Ortex** – Original author and developer of the include.

---

## 🌐 Other Languages

* [Português](https://github.com/dev-ortex/lookat/blob/main/README-pt.md)
* [English](https://github.com/dev-ortex/lookat/blob/main/README.md)
