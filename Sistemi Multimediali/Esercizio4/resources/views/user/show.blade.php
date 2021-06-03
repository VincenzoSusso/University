@extends('layouts.app')

@section('page_title', 'I Miei Hobby - Hobby')
@section('page_description', 'Qui viene mostrato un solo hobby')

@section('content')
    <div class="container">
        <div class="row justify-content-center">
            <div class="col-md-12">
                <div class="card">
                    <div class="card-header">{{$user -> name}}</div>

                    <div class="card-body">
                        <div><p class="font-weight-bold">Motto:</p>
                            <p>{{$user -> motto}}</p></div>
                        <div><p class="font-weight-bold">Su di me:</p>
                            <p>{{$user -> about_me}}</p></div>
                    </div>

                </div>
                <div class="mt-3">
                    <a class="btn btn-link btn-sm" href="{{\Illuminate\Support\Facades\URL::previous()}}">
                        <i class="fas fa-arrow-circle-up"></i> Ritorna Indietro
                    </a>
                </div>
            </div>
        </div>
@endsection
