void
stats( unsigned short n,unsigned short m )
{
	idlq *p;
	unsigned int totidle;
	unsigned short i,maxidle,minidle;

	while ( idlqh != (idlq *)0 ) {
		p = idlqh->link;
		idle[(idlqh->clrk)-1] += now-(idlqh->time);
		delete idlqh;
		idlqh = p;
	}
	for ( minidle = infinity, maxidle = totidle = i = 0;  i < m;  i++ ) {
		if ( idle[i] < minidle ) {
			minidle = idle[i];
		}
		totidle += (unsigned int)idle[i];
		if ( maxidle < idle[i] ) {
			maxidle = idle[i];
		}
	}
	cout << "minwait =" << setw( 6 ) << minwait
		<< "  meanwait =" << setw( 12 ) << setprecision( 4 )
		<< (double)totwait/(double)n
		<< "  maxwait =" << setw( 6 ) << maxwait
		<< "\nminidle =" << setw( 6 ) << minidle
		<< "  meanidle =" << setw( 12 ) << setprecision( 4 )
		<< (double)totidle/(double)m
		<< "  maxidle =" << setw( 6 ) << maxidle << '\n';
}
