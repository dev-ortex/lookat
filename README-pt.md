# 👁️ LookAt

Uma include para **Pawn** que permite detectar se um jogador está olhando para uma entidade (outro player, veículo, objeto ou actor), utilizando a direção da câmera. Ideal para sistemas de interação, diálogos imersivos, detecção de presença e outros recursos avançados de Roleplay.

---

## 📦 Instalação

1. Baixe a versão mais recente da `lookat.inc`.
2. Coloque o arquivo dentro da pasta `include/` do seu servidor.
3. Inclua no seu gamemode ou filterscript:

```pawn
#include <lookat>
```

---

## ⚙️ Funções Nativas

```pawn
native GetPlayerViewDirection(playerid, Float:scale, &Float:x, &Float:y, &Float:z);

native IsFloatBetween(Float:value, Float:center, Float:range = 2.0);
native IsPointLookingAtPoint(playerid, Float:x, Float:y, Float:z);
native IsPlayerLookingAt(playerid, E_LOOKAT_TYPE:type, targetid);
```

> \[!IMPORTANT]
>
> * `scale`: Distância à frente da câmera usada para simular o “olhar” do jogador.
> * `range`: Distância de tolerância para considerar que o jogador está olhando diretamente para o alvo.

---

## 🔢 Tipos de Entidades

| ID | Type    |
| -- | ------- |
| E_LOOKAT_PLAYER   | Player  |
| E_LOOKAT_VEHICLE  | Vehicle |
| E_LOOKAT_OBJECT   | Object  |
| E_LOOKAT_ACTOR    | Actor   |

---

## 🧪 Exemplo de Uso

```pawn
CMD:interagir(playerid)
{
    for (new i = 0; i < MAX_PLAYERS; i++)
    {
        if (i != playerid && IsPlayerLookingAtPlayer(playerid, i)) {
            SendClientMessage(playerid, -1, "Voce esta olhando para um jogador!");
        } 
        else if (IsPlayerLookingAtVehicle(playerid, i)) {
			SendClientMessage(playerid, -1, "Voce esta olhando para o seu veiculo!");
		}
    }
    return 1;
}
```

---

## 📷 Vídeo de Demonstração

https://github.com/user-attachments/assets/d32f3a7f-6e6f-4fca-9c9e-1471a62e9869

---

## 🙌 Créditos

* **Ortex** – Autor e desenvolvedor da include original.

---

## 🌐 Outros Idiomas

* [Português](https://github.com/dev-ortex/lookat/blob/main/README-pt.md)
* [English](https://github.com/dev-ortex/lookat/blob/main/README.md)
