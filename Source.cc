//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "Source.h"

namespace projetco {

Define_Module(Source);

Source::Source()
{
    timerMessage = NULL;
}

Source::~Source()
{
    cancelAndDelete(timerMessage);
}
int count=0;
 int k=0;
 int id;



 double qi[10];

    double cls,alpha,beta,np,sum1l,sum1h,sum2l,sum2h,lamdac,sumi,div,vhc,etha,mu,sumax,cr,bi,rf,sigma2,gamma;

    double sumqi,lamdaa,wlll,uhii,vhh;
    int  N;
    double sumf;

    double w;
/* int bat[10][10]={92,90,93,0,0,0,0,0,0,0,////////////////// capacity of neighbors battery
                 97,99,93,0,0,0,0,0,0,
                 91,92,80,0,0,0,0,0,0,
                 98,98,100,91,0,0,0,0,0,
                 96,97,97,0,0,0,0,0,0,
                 91,95,0,0,0,0,0,0,0,
                 99,0,0,0,0,0,0,0,0,
                 93,95,0,0,0,0,0,0,0,
                 100,0,0,0,0,0,0,0,0,};*/



 double dl[10][10]={ // distance entre 2 noeuds
        0, //distance du noeud 0 a noeud 0 est egale a 0
 21.4047,
 21.4462,////////////////////////// liens entre 1 et 3  dl[0][2]
 14.481,/////////////////////////// liens entre 1 et 4  dl[0][4]
 27.8476,/////////////////////////// liens entre 1 et 5  dl[0][5]
 35.6148,
 32.547,
 37.0818,
 46.1807,
 52.8255,
 21.4047,
 0,
 32.3152,
 16.7276,
 16.2291,
 15.9005,
 36.9928,
 32.8812,
 32.0576,
 43.6334,
 21.4462,
 32.3152,
 0,
 15.5974,
 26.1077,
 39.2882,
 12.842,
 23.476,
 40.0824,
 40.3892,
 14.481,
 16.7276,
 15.5974,
 0,
 14.4516,
 25.4536,
 21.7948,
 22.9934,
 32.2769,
 38.36,
 27.8476,
 16.2291,
 26.1077,
 14.4516,
 0,
 13.7143,
 25.0967,
 17.247,
 18.3861,
 27.7074,
 35.6148,
 15.9005,
 39.2882,
 25.4536,
 13.7143,
 0,
 38.697,
 28.9466,
 19.2616,
 33.4798,
 32.547,
 36.9928,
 12.842,
 21.7948,
 25.0967,
 38.697,
 0,
 14.09,
 33.285,
 29.7067,
 37.0818,
 32.8812,
 23.476,
 22.9934,
 17.247,
 28.9466,
 14.09,
 0,
 19.4466,
 16.9715,
 46.1807,
 32.0576,
 40.0824,
 32.2769,
 18.3861,
 19.2616,
 33.285,
 19.4466,
 0,
 15.0841,
 52.8255,
 43.6334,
 40.3892,
 38.36,
 27.7074,
 33.4798,
 29.7067,
 16.9715,
 15.0841,
 0};


 double xhl[10][10][10]={  //link rate pour chaque session h tab a 3 dimensions
 };

 double  ps[10]={0.364644,  //encoding power consumption
         0.377853,
         0.414557,
         0.45328,
         0.380829,
         0.457384,
         0.363465,
         0.454176,
         0.327096,
         0.387069};

 double lamda[10]={0.209763,
         0.218569,
         0.243038,
         0.268853,
         0.220553,
         0.271589,
         0.208977,
         0.26945,
         0.184731,
         0.224713};

 double  wl[10][10]={        0.229179,
         0.176876,
         0.187517,
         0.159507,
         0.278355,
         0.111343,
         0.292733,
         0.154531,
         0.176688,
         0.195533,
 0.209763,
         0.218569,
         0.243038,
         0.268853,
         0.220553,
         0.271589,
         0.208977,
         0.26945,
         0.184731,
         0.224713,
         0.117426,
         0.229634,
         0.104044,
         0.173648,
         0.266524,
         0.291431,
         0.255631,
         0.12807,
         0.274002,
         0.274017,
         0.258345,
         0.262434,
         0.205779,
         0.195995,
         0.213609,
         0.178557,
         0.285119,
         0.267216,
         0.114207,
         0.167479,
         0.227984,
         0.216404,
         0.128671,
         0.207475,
         0.288934,
         0.251723,
         0.20437,
         0.121182,
         0.182932,
         0.19472,
         0.295724,
         0.194722,
         0.259832,
         0.260182,
         0.192296,
         0.204095,
         0.256106,
         0.235776,
         0.123655,
         0.244127,
         0.152911,
         0.137266,
         0.254847,
         0.247384,
         0.19123,
         0.14331,
         0.213687,
         0.127044,
         0.103758,
         0.164828,
         0.223527,
         0.129935,
         0.222419,
         0.144464,
         0.223387,
         0.177298,
         0.28875,
         0.28052,
         0.236364,
         0.18999,
         0.171902,
         0.222613,
         0.187406,
         0.28047,
         0.239526,
         0.119856,
         0.112045,
         0.293962,
         0.233353,
         0.230628,
         0.234128,
         0.134182,
         0.142077,
         0.17163,
         0.125785,
         0.250137,
         0.163086,
         0.221566,
         0.172742,
 0.165009
 };
 double  uhi[10][10]={0.209763,
         0.218569,
         0.243038,
         0.268853,
         0.220553,
         0.271589,
         0.208977,
         0.26945,
         0.184731,
         0.224713,
         0.229179,
         0.176876,
         0.187517,
         0.159507,
         0.278355,
         0.111343,
         0.292733,
         0.154531,
         0.176688,
         0.195533,
         0.258345,
         0.262434,
         0.205779,
         0.195995,
         0.213609,
         0.178557,
         0.285119,
         0.267216,
         0.114207,
         0.167479,
         0.117426,
         0.229634,
         0.104044,
         0.173648,
         0.266524,
         0.291431,
         0.255631,
         0.12807,
         0.274002,
         0.274017,
         0.295724,
         0.194722,
         0.259832,
         0.260182,
         0.192296,
         0.204095,
         0.256106,
         0.235776,
         0.123655,
         0.244127,
         0.227984,
         0.216404,
         0.128671,
         0.207475,
         0.288934,
         0.251723,
         0.20437,
         0.121182,
         0.182932,
         0.19472,
         0.152911,
         0.137266,
         0.254847,
         0.247384,
         0.19123,
         0.14331,
         0.213687,
         0.127044,
         0.103758,
         0.164828,
         0.223527,
         0.129935,
         0.222419,
         0.144464,
         0.223387,
         0.177298,
         0.28875,
         0.28052,
         0.236364,
         0.18999,
         0.171902,
         0.222613,
         0.187406,
         0.28047,
         0.239526,
         0.119856,
         0.112045,
         0.293962,
         0.233353,
         0.230628,
         0.234128,
         0.134182,
         0.142077,
         0.17163,
         0.125785,
         0.250137,
         0.163086,
         0.221566,
         0.172742,
         0.165009};
 double nhi[10][10]={0.209763,
         0.218569,
         0.243038,
         0.268853,
         0.220553,
         0.271589,
         0.208977,
         0.26945,
         0.184731,
         -0.224713,
         0.229179,
         0.176876,
         0.187517,
         0.159507,
         0.278355,
         0.111343,
         0.292733,
         0.154531,
         0.176688,
         -0.195533,
         0.258345,
         0.262434,
         0.205779,
         0.195995,
         0.213609,
         0.178557,
         0.285119,
         0.267216,
         0.114207,
         -0.167479,
         0.117426,
         0.229634,
         0.104044,
         0.173648,
         0.266524,
         0.291431,
         0.255631,
         0.12807,
         0.274002,
         -0.274017,
         0.295724,
         0.194722,
         0.259832,
         0.260182,
         0.192296,
         0.204095,
         0.256106,
         0.235776,
         0.123655,
         -0.244127,
         0.227984,
         0.216404,
         0.128671,
         0.207475,
         0.288934,
         0.251723,
         0.20437,
         0.121182,
         0.182932,
         -0.19472,
         0.152911,
         0.137266,
         0.254847,
         0.247384,
         0.19123,
         0.14331,
         0.213687,
         0.127044,
         0.103758,
         -0.164828,
         0.223527,
         0.129935,
         0.222419,
         0.144464,
         0.223387,
         0.177298,
         0.28875,
         0.28052,
         0.236364,
         -0.18999,
         0.171902,
         0.222613,
         0.187406,
         0.28047,
         0.239526,
         0.119856,
         0.112045,
         0.293962,
         0.233353,
         -0.230628,
         0.234128,
         0.134182,
         0.142077,
         0.17163,
         0.125785,
         0.250137,
         0.163086,
         0.221566,
         0.172742,
        - 0.165009};
 double vh[10]={0.209763,
         0.218569,
         0.243038,
         0.268853,
         0.220553,
         0.271589,
         0.208977,
         0.26945,
         0.184731,
         0.224713,
 };
 double r[10]={0.154881,   //source rate
         0.159284,
         0.171519,
         0.184427,
         0.160276,
         0.185795,
         0.154488,
         0.184725,
         0.142365,
         0.162356};
 double ail[10][10]={0,0,1,1,1,0,0,0,0,0,
                     0,0,0,1,1,1,0,0,0,0,
                    -1,0,0,0,1,0,1,1,0,0,
                    -1,-1,0,0,1,1,1,1,0,0,
                    -1,-1,-1,-1,0,1,0,0,1,1,
                     0,-1,0,-1,-1,0,0,1,1,0,
                     0,0,-1,-1,0,0,0,0,0,1,
                     0,0,-1,-1,0,-1,0,0,1,1,
                     0,0,0,0,-1,-1,0,-1,0,1,
                     0,0,0,0,-1,0,-1,-1,-1,0
         };
 double ailp[10][10]={0,0,1,1,1,0,0,0,0,0,
                      0,0,0,1,1,1,0,0,0,0,
                      0,0,0,0,1,0,1,1,0,0,
                      0,0,0,0,1,1,1,1,0,0,
                      0,0,0,0,0,1,0,0,1,1,
                      0,0,0,0,0,0,0,1,1,0,
                      0,0,0,0,0,0,0,0,0,1,
                      0,0,0,0,0,0,0,0,1,1,
                      0,0,0,0,0,0,0,0,0,1,
                      0,0,0,0,0,0,0,0,0,0};

 double ailm[10][10]={0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,
                      1,0,0,0,0,0,0,0,0,0,
                      1,1,0,0,0,0,0,0,0,0,
                      1,1,1,1,0,0,0,0,0,0,
                      0,1,0,1,1,0,0,0,0,0,
                      0,0,1,1,0,0,0,0,0,0,
                      0,0,1,1,0,1,0,0,0,0,
                      0,0,0,0,1,1,0,1,0,0,
                      0,0,0,0,1,0,1,1,1,0};

 //int L=22; //directed wireless links
 int V=9;  //video n
 int h=1;
 //int l=1;
 double epsilon=1e-10;
 double cccsl = 0;




void Source::initialize()
{
    ev<<"initialize"<<endl;

    k=0;
       alpha=0.5;
       beta=1.3E-8;
       np=4; //path loss exponent
       sigma2=3500;
       gamma=55.54; // doit etre 55.54 ??
       cr=0.5;
       bi=5.0;
       rf=0.2; // regularization factor
       N=9; //nombre de noeuds
       w=0.15;  //step size parameter


    //timerMessage = new cMessage("timer");
   // scheduleAt(simTime(), timerMessage);
    cMessage *msg = new cMessage("Iteration");
    msg->setKind(0);
        // int out2=gateSize("out2");
         int out =gateSize("out");
         ev<<"out="<<out<<endl;

       for(int i=0;i<out;i++){
             send (msg->dup(),"out",i);}
      //  cMessage *duty = new cMessage("Video_data");

            //   duty->setKind(1);
              //   for(int i=0;i<out2;i++){
                    //   send (duty->dup(),"out2",i); }
}



double Source::dis (int src,int des)//////// return the distance between source and destination
{
    return dl[src][des];
}

double Source:: ethac (int h,int i ,double rh[])/////return rh
{
    ev<<"h"<<h<<endl;
    ev<<"i"<<i<<endl;
    ev<<"rh"<<rh[h]<<endl;
    double ret = 0;
    if (i == h ){
        ret =rh[h];
    } else{
        if( i==9){//if sink
         ret = -rh[h];}
    }
    return ret ;
}

double Source::ccsl (int src,int des)/////return csl
{
    cls=alpha+beta*pow(dl[src][des],np);
    return cls;
}

double Source::wij (int isrc,int ides)///////////return i
{
    return wl[isrc][ides];  //  doit etre return wl ??
}

void Source::flamda (int i)// function return lambda
{
    double      sump=0;
    for(int i0=0;i0<N;i0++){
        for(int j=0;j<N;j++){
            double  sumx=0;
            for(int h=0;h<V;h++){
                sumx=sumx+xhl[h][i0][j];
            }
            if (i0 == i){
                sump=sump+(ailp[i][j]*ccsl(i,j)*sumx);
            }
        }
    }

    double      summ=0;
    for(int i0=0;i0<N;i0++){
        for(int j=0;j<N;j++){
            double  sumx=0;
            for(int h=0;h<V;h++){
                sumx=sumx+xhl[h][i0][j];
            }
            if (i0 == i){
                summ=summ+(ailm[i][j]*cr*sumx);
            }
        }
    }

    double fg=(((double)w)/sqrt(k))*(qi[i]*bi-sump-summ-ps[i]) ;
    lamdac=lamda[i]-fg;
    //ev<< "lamda b4 test max------------------"<< lamdac<< endl;

    if(lamdac>0)
        lamda[i]=lamdac;
    else {
        lamda[i]=0;
    }
    /////        ev<<"lamda after test ----------->   "<<lamda[i]<<endl;
    /////       ev<<"                               "<<endl;
}


void Source::fwl (int i0)// ///////////// function wl
{
    for (int je=0;je<N;je++){
        if (ail[i0][je] == 1){
            wl[i0][je] = wl[i0][je] + (((double)w)/sqrt(k))*(qi[i0]-qi[je]);
        }
    }
}


void Source::fvh (int h) ///////////// function return vh
{
    double x=0;
    div=((double)log(sigma2)/100)/(gamma*pow(ps[h],((double)2)/3));
    x=(((double)w)/sqrt(k))*(r[h]-div);
    vhc=vh[h]-x;
    if(vhc>0)
        vh[h]=vhc;
    else {
        vh[h]=0;
    }
}

void Source::fuhi (int i) ///////////// function return u hi
{
    double tempo, calc;
    for(int h=0;h<V;h++){
        double sumqi = 0;
        // for outgoing links
        for(int rid=0;rid<N;rid++){
            sumqi=sumqi+ail[i][rid]*xhl[h][i][rid];
        }
        // for ingoing links
       /* for(int rid=0;rid<N;rid++){
            sumqi=sumqi+ail[rid][i]*xhl[h][rid][i];
        }*/
        calc= ethac (h,i ,r);

        uhi[h][i]=uhi[h][i]-((((double)w)/(sqrt(k)))*(calc-sumqi));

         tempo=((((double)w)/(sqrt(k)))*(calc-sumqi));

    }
    //ev<<"-------------calcul uhi-------------->   "<<tempo<<endl;
    //ev<<"-------------uhi-------------->   "<<uhi[h][i]<<endl;
    ev<<"-------------calc-------------->   "<<calc<<endl;
}


void Source::fqi (int id) ///////////// function return qi
{
    bi=5.0;
    double sumqi=0;
    double test;
    // for outgoing links
    for(int rid=0;rid<N;rid++){
        double  wll= wij(id,rid);
        test=ail[id][rid]*wll;
      sumqi=sumqi+ail[id][rid]*wll;

    }
    // for ingoing links
 /* for(int rid=0;rid<N;rid++){
        double  wll= wij(rid,id);
      sumqi=sumqi+ail[rid][id]*wll;

    }*/
    /////     ev<<"somme"<<sumqi<<endl;
    /////     ev<<"lmda*b"<<lamda[id]*bi<<endl;
    double sumqii=((double)-(sumqi-lamda[id]*bi))/2;
    if(sumqii>epsilon)
    {
        qi[id]=sumqii;
              ev<<"-------------qi-------------->   "<<qi[id]<<endl;

    }
    else
    {
        qi[id]=epsilon;
    }


}

void Source::fpsh (int id) ///////////// function return ps
{
    double deltap=0.2;
    double gamma=55.54;
    double a= -3*lamda[id];
  //  double b= sqrt(pow(3*lamda[id],2)+((double)(64*deltap))/gamma*log(((double)sigma2)/100))  ;

   double b= sqrt((pow(3*lamda[id],2))+(((double)((64*deltap)))*(log(((double)sigma2)/100))*vh[id])/gamma);
    double c =a+b;
    double sump=  ((double)c)/(16*deltap);
    double sumph=pow(sump,0.6);
    if(sumph>epsilon)
        ps[id]=sumph;
    else
    {
        ps[id]=epsilon;
    }
  ev<<"-------------ps-------------->   "<<ps[id]<<endl;
}

void Source::frh (int id) ///////////// function return rh
{

    double deltar =0.2;
    double resultatrh=((double)vh[id])/(2*deltar);
    epsilon=1e-10;
    if(resultatrh>0)
        r[id]=resultatrh;
    else
    {
        r[id]=0;
    }
         ev<<"rh      "<<r[id]<<endl;
}


void Source::fxhl (int h) ///////////// function return xhl
{
    double xht=0;
    double deltax=0.2;
    for(int i0=0; i0<N; i0++){
        for (int je=0 ; je<N; je++){
            double cccsl = ccsl(i0,je);
            double xhs=0;
            for(int i=0;i<N;i++) {
                int ailpp = 0;
                int ailmm = 0;
                int aill = 0;
                if (i==i0){
                    ailpp = ailp[i][je];
                    ailmm = ailm[i][je];
                    aill = ail[i][je];
                }
                xhs=xhs+(lamda[i]*(cccsl *ailpp+cr*ailmm)+uhi[h][i]*aill);
            }
            xht=((double)-xhs)/(2*deltax);
            if(xht>0){
                xhl[h][i0][je]=xht;
            }
            else {
                xhl[h][i0][je]=0;
            }
            //if (xhl[h][i0][je]>0){
             //  ev<<"xhl["<<h<<"]["<<i0<<"]["<<je<<"] after test "<<xhl[h][i0][je]<<endl;
           // }
        }
    }
}

void Source::handleMessage(cMessage *msg)
{
    double deltax =0.2;
                       double deltar =0.2;
                       double deltap =0.2;
                      /* double sqi=0;
                       double spsh=0;
                       double srh=0;
                       double sxhl=0;
                       double old;*/
                       double fabst;

 //double t= dblrand()*5;
 //ev<<"t"<<t<<endl;
   /* ASSERT(msg==timerMessage);

    cMessage *job = new cMessage("job");
    send(job, "out");

    scheduleAt(simTime()+par("sendInterval").doubleValue(), timerMessage);*/
    int o= gateSize("out");
    int o2= gateSize("out2");
    ev<<"Handle message"<<endl;
    int in =gateSize("in");
    ev<<"in="<<in<<endl;
  // cMessage *ack = new cMessage("ack");
     //  ack->setKind(0);
       cMessage *keep= new cMessage("keep_data");
      keep->setKind(1);
             int id=getIndex();
             ev<<"noeud numero:"<<id<<endl;

            for (int i=0;i<in;i++){
                int kd= msg->getKind();
            if (kd == 0){
                          count++;
            }




           }
            ev<<"test count"<<endl;
            ev<<"count="<<count<<endl;
           if (count== gateSize("in")){
               ev<<"count= in alors iter ++"<<endl;
               count=0;
               k++;
               ev<<"noeud numero:"<<id<<endl;
               ev<<"iteration numero:"<<k<<endl;

                  for (int id1=0;id1<N;id1++){
                     // ev<<"id1++"<<endl;
               flamda(id1);//calculate lambda
               fwl(id1);//calculate wl
               fvh(id1);//calculate vh
               fuhi(id1);//calculate uhi
               fqi(id1);//calculate qi
               fpsh(id1);//calculate psh
               frh(id1);//calculate rh
               fxhl(id1);//calculate xhl
              double sqi=0;
                   double spsh=0;
                   double srh=0;
                   double sxhl=0;
                   double old=sumf;
                   /*  sumf=0;
              // ev<<"qi[id1]="<<qi[id1]<<endl;
              // ev<<"sqi"<<sqi<<endl;
                  for (int i=0;i<N;i++){
                     // ev<<qi[i]<<endl;

                       sqi=sqi+(qi[i]*qi[i]);


                   }
                   //ev<<"sqi= "<<sqi<<endl;
               for (int i=0;i<N;i++){
                   for (int j=0;j<N;j++){
                   for (int h=0;h<V;h++){
                       sxhl=sxhl+(xhl[h][h][j]*xhl[h][h][j]);
                     }
                 }}
                      // ev<<"sxhl:"<<sxhl<<endl;

                   for (int h=0;h<V;h++){
                       srh=srh+(r[h]*r[h]);
                       }
                  // ev<<"srh:"<<srh<<endl;
                   for (int h=0;h<V;h++){
                       spsh=spsh+(pow(ps[h],0.6666666667));
                       }
                   //ev<<"spsh:"<<spsh<<endl;

                   sumf=sqi+deltax*sxhl+deltar*srh+deltap*spsh;

                   ev<<"old eq3= "<<old<<endl;
                   ev<<"new eq3= "<<sumf<<endl;
                   fabst=fabs((old-sumf));
                  ev<<"la difference est"<<fabst<<endl;

                  }



  if (fabst>1E-5)
   {*/



                  } for(int i=0;i<N;i++){
                                          ev<<"qi["<<i<<"]"<<qi[i]<<endl;
                                      }
                                double max = qi[0];
                                double min = qi[0];

                                for(int i = 1; i<N; i++)
                                   {
                                        if(qi[i] > max){

                                              max = qi[i];
                                   }
                                        if(qi[i] < min){

                                                          min = qi[i];
                                               }
                                               // return highest value in array
                              }
                                   ev<<""<<endl;
                                ev<<"max qi"<<max<<endl;
                                ev<<"min qi"<<min<<endl;


                            double div=(max/min)-1;
                            double p100=div*100;

                            ev<<"difference %" <<p100<<endl;
                     if (p100>10){

                    ev<<"Incremente les iterations"<<endl;
                    keep->setKind(1);
                    msg->setKind(0);
                    for(int i=0;i<o;i++){

              send(msg->dup(),"out",i);
                    }
                    for(int i=0;i<o2;i++){

              send(keep->dup(),"out2",i);
                    }
                     }

                     else{

                            ev<<"arrete les iterations, envoie keep_iteration "<<endl;
                            keep->setKind(1);
                            for(int i=0;i<o2;i++){
                         send (keep->dup(),"out2",i);
                            }
                        // endSimulation ();

                     }
           }
           else{

               ev<<"attendre les autres noeuds pour envoyer ack"<<endl;
               for(int i=0;i<o2;i++){
               send(keep->dup(),"out2",i);
               }
           }


   }
};// namespace
