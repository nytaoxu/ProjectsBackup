
from django.contrib import admin
from django.urls import path
from django.conf.urls import include, url
from . import views
urlpatterns = [
	url(r'^$',views.post_list,name='post_list'),
	url(r'^post/(?P<pk>\d+)/$',views.post_details,name='post_details'),
	url(r'^post/new/$',views.post_new,name='post_new'),
]
