//家常豆腐
inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name("家常豆腐", ({ "doufu", "jcdf" }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一盆刚烧好的家常豆腐。\n");
                set("unit", "盆");
                set("value", 100);
                set("food_remaining", 3);
                set("food_supply", 25);
        }
    setup();
}
