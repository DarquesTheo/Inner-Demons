/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** init_inv_res
*/

#include "res.h"
#include <stdlib.h>

static void check_loading_sucess(inv_res_t *inv_res)
{
    if (inv_res->font == NULL || inv_res->heart_full == NULL)
        exit(84);
    if (inv_res->heart_quarter == NULL || inv_res->heart_semi == NULL)
        exit(84);
    if (inv_res->heart_three == NULL || inv_res->slot == NULL)
        exit(84);
    if (inv_res->heart_empty == NULL || inv_res->coin == NULL)
        exit(84);
    if (inv_res->shop_bg == NULL || inv_res->equip_left == NULL)
        exit(84);
    if (inv_res->equip_right == NULL || inv_res->delete == NULL)
        exit(84);
    if (inv_res->interactbg == NULL || inv_res->sell == NULL)
        exit(84);
    if (inv_res->shopbtn == NULL || inv_res->merge == NULL)
        exit(84);
}

void init_inv_res_two(inv_res_t *inv_res)
{
    inv_res->shop_bg = sfTexture_createFromFile(
        "res/inventory/shopbg.png", NULL);
    inv_res->equip_left = sfTexture_createFromFile(
        "res/inventory/equip_left_hand.png", NULL);
    inv_res->equip_right = sfTexture_createFromFile(
        "res/inventory/equip_right_hand.png", NULL);
    inv_res->delete = sfTexture_createFromFile(
        "res/inventory/delete.png", NULL);
    inv_res->interactbg = sfTexture_createFromFile(
        "res/inventory/Interactbg.png", NULL);
    inv_res->sell = sfTexture_createFromFile(
        "res/inventory/sell.png", NULL);
    inv_res->shopbtn = sfTexture_createFromFile(
        "res/inventory/shopbtn.png", NULL);
    inv_res->merge = sfTexture_createFromFile(
        "res/inventory/merge.png", NULL);
}

inv_res_t *init_inv_res(void)
{
    inv_res_t *inv_res = malloc(sizeof(inv_res_t));

    inv_res->slot =
        sfTexture_createFromFile("res/inventory/Inventory_Slot_1.png", NULL);
    inv_res->font = sfFont_createFromFile("res/inventory/inventory_font.ttf");
    inv_res->heart_full = sfTexture_createFromFile(
        "res/inventory/Heart_Full.png", NULL);
    inv_res->heart_three = sfTexture_createFromFile(
        "res/inventory/Heart_Almost_Full.png", NULL);
    inv_res->heart_semi = sfTexture_createFromFile(
        "res/inventory/Heart_Demi.png", NULL);
    inv_res->heart_quarter = sfTexture_createFromFile(
        "res/inventory/Heart_Almost_Empty.png", NULL);
    inv_res->heart_empty = sfTexture_createFromFile(
        "res/inventory/Heart_Empty.png", NULL);
    inv_res->coin = sfTexture_createFromFile(
        "res/inventory/Coin.png", NULL);
    init_inv_res_two(inv_res);
    check_loading_sucess(inv_res);
    return inv_res;
}
