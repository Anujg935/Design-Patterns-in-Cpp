//Adapter design Pattern
//Adapter pattern works as a bridge between two incompatible interfaces. 
//This type of design pattern comes under structural pattern as this pattern combines the capability of two independent interfaces.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//MediaPlayer Interface
class MediaPlayer{
	public:
		virtual void play(string audioType, string fileName) = 0;
};

//AdvancedMediaPlayer Interface
class AdvancedMediaPlayer{
	public:
		virtual void playVlc(string fileName) = 0;
		virtual void playMp4(string fileName) = 0;
};

//Concrete class for AdvancedMediaplayer Interface
//For vlc type of audio
class VlcPlayer : public AdvancedMediaPlayer{
	public:
		void playVlc(string fileName){
			cout << "Playing VLC file name: " << fileName << endl;
		}
		
		void playMp4(string fileName){
			//do nothing
		}
};

//Concrete class for AdvancedMediaplayer Interface
//For mp4 type of audio
class Mp4Player : public AdvancedMediaPlayer{
	public:
		void playMp4(string fileName){
			cout << "Playing Mp4 file name: " << fileName << endl;
		}
		
		void playVlc(string fileName){
			// do nothing
		}
};


// Creating adapter class implementing MediaPlayer Interface
class MediaAdapter : public MediaPlayer{
	AdvancedMediaPlayer * advancedMusicPlayer;
	
	public:
		MediaAdapter(string audioType){
			if(audioType == "vlc"){
				advancedMusicPlayer = new VlcPlayer();
			}
			else if(audioType == "mp4"){
				advancedMusicPlayer = new Mp4Player();
			}
		}
		
		void play(string audioType, string fileName){
			if(audioType == "vlc"){
				advancedMusicPlayer->playVlc(fileName);
			}
			else if(audioType == "mp4"){
				advancedMusicPlayer->playMp4(fileName);
			}
		}
};

//create concrete class implementing MediaPlayer Interface
class AudioPlayer : public MediaPlayer{
	MediaAdapter *mediaAdapter;
	public:
		
		void play(string audioType, string fileName){
			if(audioType == "mp3"){
				cout << "Playing mp3 file name:- " << fileName << endl;
			}
			else if(audioType == "mp4" || audioType == "vlc"){
				mediaAdapter = new MediaAdapter(audioType);
				mediaAdapter->play(audioType, fileName);
			}
			else{
				cout << "Invalid media. " << audioType <<" format not supported" <<endl;
			}
		}
};
int main()
{
	AudioPlayer *audio = new AudioPlayer();
	
	audio->play("mp3", "hello.mp3");
	audio->play("vlc", "hi.vlc");
	audio->play("mp4", "world.mp4");
	audio->play("avi", "Anuj.avi");
}
