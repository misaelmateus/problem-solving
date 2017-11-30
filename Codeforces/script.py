from bs4 import BeautifulSoup
import urllib2
import os
import time
handle = raw_input("Type your handle : ")

for i in range(42, 63):
	print 'grabbing data'
	gen_url = 'http://codeforces.com/submissions/'+handle+'/page/' + str(i)
	print gen_url
	r = urllib2.urlopen(gen_url)
	time.sleep(3)
	print 'done'

	problem_id = []
	no_name = []

	soup = BeautifulSoup(r)
	co = soup.find_all('td')

	for row in range(1,len(co)):
		if len(co[row].attrs) == 4:
			if len(co[row].span.attrs) == 5:
				if co[row].span.attrs['submissionverdict'] == 'OK':
					problem_id.append(co[row].span.attrs['submissionid'])
					no_name.append(row)

	contest_id = []
	for j in range(0,len(no_name)):
		query = no_name[j]
		contest_id.append(co[query-2].a.attrs['href'].split('/')[3])

	for j in range(0, len(contest_id)):
		url = 'http://codeforces.com/contest/'+contest_id[j]+'/submission/'+problem_id[j]
		if len(contest_id[j]) > 4:
			continue
		print url
		r = urllib2.urlopen(url)
		time.sleep(3)
		soup = BeautifulSoup(r)
		var = soup.find_all('td')
		var1 = soup.find('div', attrs={"style" : "background-color: white;margin:0.3em 3px 0 3px;position:relative;"}).find_all('td')
		problem_name = var[2].a['href'].split('/')[4]
		print 'getting code '+contest_id[j]+'-'+problem_name
		
		co = soup.find_all('div')
		
		target = open(contest_id[j]+'-'+problem_name + '.cpp', "w")
		target.write("//   Author : Misael Mateus \n")
		target.write("//   Submission date: " + var1[8].text + "\n")
		for row in range(0,len(co)):
			flag = 0
			for row in co[row].find_all('pre',attrs={"class" : "prettyprint lang-cpp program-source"}):
				target.write(row.text)
				flag = 1
			if flag == 1: 
				break
		print 'got code '+contest_id[j]+'-'+problem_name
		target.close()	
