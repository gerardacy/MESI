												

if (key1==6) {
				
					cout << "\nDude, are u sure?\n"; 
							for (int i=0; i<2; i++)	{
														if (key2==i+1) 
																		cout << "  *" << razd[key1-1].mass[i] << "*";
																													else 
																		cout << "   " << razd[key1-1].mass[i] << " ";
													}

						w=getch();
						if (w==224)
									w=getch();
						switch (w) {
									case 77:
											key2++;
											break;
									case 75:
											key2--;
											break;
									}
						if (key2>2)key2=1;
						if (key2<1)key2=2;
						system ("cls");
						if (key2==2) 
									switch (w) {
												case 13:
														F=true;
														key2=1;
														break;
												}
					
																else
						if (key2==1) 
									switch (w) {
												case 13:
														exit(1);
														break;
												}
					}  