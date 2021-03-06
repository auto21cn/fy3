// vendor.c
// music 

#include <dbase.h>

int buy_object(object me, string what)
{
/*	string ob;

	if( stringp(ob = query("vendor_goods/" + what)) )
		return ob->query("value");
	else
		return 0;
*/
        mapping goods;
        string  *name;
        int i;
        if( !mapp(goods = query("vendor_goods")) ) return 0;
        name = keys(goods);
        for(i=0; i<sizeof(name); i++)
		if (  goods[name[i]]->id(what))
			return goods[name[i]]->query("value");
	return 0;
}

void compelete_trade(object me, string what)
{
/*	string ob_file;
	object ob;

	if( stringp(ob_file = query("vendor_goods/" + what)) ) {
		ob = new(ob_file);
		ob->move(me);
		message_vision("$N向$n买下一" + ob->query("unit") + ob->query("name") + "。\n",
			me, this_object() );
	}
*/
        mapping goods;
        object ob;
        string  *name;
        int i;
        if( !mapp(goods = query("vendor_goods")) ) return 0;
        name = keys(goods);
        for(i=0; i<sizeof(name); i++)
                if (  goods[name[i]]->id(what)) {
			ob = new(goods[name[i]]);
                	ob->move(me);
                message_vision("$N向$n买下一" + ob->query("unit") + ob->query("name") + "。\n",
                        me, this_object() );
			break;
		}
}

string price_string(int v)
{
	if( v%10000 == 0 )
		return (v/10000) + "两黄金";
	if( v%100 == 0 )
		return (v/100) + "两银子";
	return v + "文钱";
}

string value_string(int value)
{
        if( value < 1 ) value = 1;
        else if( value < 100 )
                return chinese_number(value) + "文钱";
        else
                return chinese_number(value/100) + "两"
                        + (value%100? "又" + chinese_number(value%100) + "文钱": "");
}

int do_vendor_list(string arg)
{
	mapping goods;
	string list, *name;
	int i;

	if( !mapp(goods = query("vendor_goods")) ) return 0;
	if( arg && !this_object()->id(arg) ) return 0;
	name = keys(goods);
	list = "你可以购买下列这些东西：\n";
	list += "-----------------------------------------------------------------------------\n  ";
	for(i=0; i<sizeof(name); i++)
		list += sprintf("%-50s%s\n  ",
			goods[name[i]]->short(),
			value_string(goods[name[i]]->query("value")) );
/*			price_string(goods[name[i]]->query("value")) );*/
	list +="\n";
	write(list);
	return 1;	
}
