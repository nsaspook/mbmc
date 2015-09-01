function demo() {
	demo1();
	demo2();
	demo3();
	demo4();
	demo5();	
}


function demo1(painterType) {
	var c = new Chart(document.getElementById('chart'));
	c.setDefaultType(CHART_LINE);
	c.setGridDensity(24, 24);
	c.setVerticalRange(0, 23);
	c.setHorizontalLabels(['0','1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12','13', '14', '15', '16', '17', '18', '19', '20', '21', '22', '23']);
	c.setBarWidth(10);
	c.add('PV Volts',      	'red', 	 mymbmc11);
	c.add('CC Volts',      	'#AD0000', mymbmc10);
	c.add('Battery 1',     	'blue',  mymbmc12);
	c.add('Battery 2', 	'#FF00FF',  mymbmc13);
	c.add('Control Volts', 	'black',   [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0]);
	c.add('PV Current',     '#FF4500',mymbmc15);
	c.add('Load Current',   '#FFA500',mymbmc16);
	c.add('PV Power',   	'#00FF00',mymbmc17);
	c.add('Load Power',   	'#009900',mymbmc18);
	c.draw();
}

function demo2() {
	var c = new Chart(document.getElementById('chart2'));
	c.setDefaultType(CHART_LINE);
	c.setGridDensity(24, 24);
	c.setVerticalRange(0, 23);
	c.setHorizontalLabels(['0','1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12','13', '14', '15', '16', '17', '18', '19', '20', '21', '22', '23']);
	c.setBarWidth(10);
	c.add('PV Volts',      	'red', 	 mymbmc21);
	c.add('CC Volts',      	'#AD0000', mymbmc20);
	c.add('Battery 1',     	'blue',  mymbmc22);
	c.add('Battery 2', 	'#FF00FF',  mymbmc23);
	c.add('Control Volts', 	'black',   [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0]);
	c.add('PV Current',     '#FF4500',mymbmc25);
	c.add('Load Current',   '#FFA500',mymbmc26);
	c.add('PV Power',   	'#00FF00',mymbmc27);
	c.add('Load Power',   	'#009900',mymbmc28);
	c.draw();
}

function demo3() {
	var c = new Chart(document.getElementById('chart3'));
	c.setDefaultType(CHART_LINE);
	c.setGridDensity(24, 24);
	c.setVerticalRange(0, 23);
	c.setHorizontalLabels(['0','1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12','13', '14', '15', '16', '17', '18', '19', '20', '21', '22', '23']);
	c.setBarWidth(10);
	c.add('PV Volts',      	'red', 	 mymbmc31);
	c.add('CC Volts',      	'#AD0000', mymbmc30);
	c.add('Battery 1',     	'blue',  mymbmc32);
	c.add('Battery 2', 	'#FF00FF',  mymbmc33);
	c.add('Control Volts', 	'black',   [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0]);
	c.add('PV Current',     '#FF4500',mymbmc35);
	c.add('Load Current',   '#FFA500',mymbmc36);
	c.add('PV Power',   	'#00FF00',mymbmc37);
	c.add('Load Power',   	'#009900',mymbmc38);
	c.draw();
}

function demo4() {
	var c = new Chart(document.getElementById('chart4'));
	c.setDefaultType(CHART_AREA | CHART_STACKED);
	c.setGridDensity(24, 20);
	c.setVerticalRange(0, 200);
	c.setHorizontalLabels(['0','1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12','13', '14', '15', '16', '17', '18', '19', '20', '21', '22', '23']);
	c.setBarWidth(10);
	c.add('Battery 2 SOC',    'blue', mymbmc44);
	c.add('Battery 1 SOC',    'red',  mymbmc43);
	c.draw();
}

function demo5() {
	var c = new Chart(document.getElementById('chart5'));
	c.setDefaultType(CHART_AREA | CHART_STACKED);
	c.setGridDensity(24, 30);
	c.setVerticalRange(0, 300);
	c.setHorizontalLabels(['0','1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12','13', '14', '15', '16', '17', '18', '19', '20', '21', '22', '23']);
	c.add('PV Eff',      	'green', mymbmc40);
	c.add('Load Factor',    'red',  mymbmc41);
	c.add('CC Eff',      	'blue', mymbmc42);
	c.draw();
}