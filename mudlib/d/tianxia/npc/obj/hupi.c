inherit ITEM;
void create()
{
  set_name("虎皮", ({"hu pi"}));
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一张完整的虎皮,满布黄白相间的条纹。\n");
    set("unit", "张");
    set("value", 1000);
  }
}


