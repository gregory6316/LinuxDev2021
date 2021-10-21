range: range.c
	gcc range.c -o range -g -O0

test: range
	gdb < gdb_scenario_1.txt ./range | grep '@@@' | awk -F "= " '{ print $$2 }' > gdb_res_1.txt
	cmp gdb_res_1.txt gdb_res_1_standart.txt

	gdb < gdb_scenario_2.txt ./range | grep '@@@' | awk -F "= " '{ print $$2 }' > gdb_res_2.txt
	cmp gdb_res_2.txt gdb_res_2_standart.txt
clean: 
	rm -rf gdb_res_1.txt gdb_res_2.txt range
