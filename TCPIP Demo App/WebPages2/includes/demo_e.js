function demo_e() {
	demo1_e();
	demo4_e();	
}


function demo1_e(painterType) {
	var c = new Chart(document.getElementById('chart_e'));
	c.setDefaultType(CHART_LINE);
	c.setGridDensity(24, 24);
	c.setVerticalRange(0, 23);
	c.setHorizontalLabels(['0','1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12','13', '14', '15', '16', '17', '18', '19', '20', '21', '22', '23']);
	c.setBarWidth(10);
	c.add('PV Energy',      	'red', 	 mymbmc50);
	c.add('PV Energy Total',      	'green', mymbmc51);
	c.add('PV Usage', 	'#FF00FF',  mymbmc53);
	c.add('PV Usage Total',     'blue',mymbmc54);
	c.add('AC Diversion',   	'#00FF00',mymbmc56);
	c.draw();
}


function demo4_e() {
	var c = new Chart(document.getElementById('chart4_e'));
	c.setDefaultType(CHART_AREA | CHART_STACKED);
	c.setGridDensity(24, 20);
	c.setVerticalRange(0, 200);
	c.setHorizontalLabels(['0','1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12','13', '14', '15', '16', '17', '18', '19', '20', '21', '22', '23']);
	c.setBarWidth(10);
	c.add('PV Energy Total',    'green',  mymbmc51);
	c.add('PV Usage Total',    'blue', mymbmc54);
	c.add('AC Diversion',    '#00FF00', mymbmc56);
	c.draw();
}
