// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

inherit ITEM;

void create()
{
        set_name("铁浮屠", ({ "tie futu" }) );
        set_weight(500000);
        set_max_encumbrance(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "座");
                set("long", "这是佛门中的浮屠,上面雕刻着金刚经。\n");
                set("value", 50);
        }
}


